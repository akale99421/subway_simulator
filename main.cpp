#include <queue>

#include <iostream>

#include <string>

#include "scripts/headers/Event.h"

#include "scripts/headers/EventFactory.h"

#include <vector>

#include <map>

#include "scripts/headers/Person.h"

#include "scripts/headers/Exceptions.h"

#include <random>

const int INIT_PASSENGER_EVENTS = 1000;

const int START_TIME = 0;

const int END_TIME = 1440;

std::random_device rand_dev;
std::mt19937 generator(rand_dev());

template<typename T>
T random(T start, T end) {
    std::uniform_int_distribution<T> distr(start, end);
    return distr(generator);
}


const std::string STATIONS[10] = {
    "Delancey St-Essex St",
    "Broadway-Lafayette St",
    "W 4 St-Washington Sq",
    "14 St-Union Sq",
    "23 St",
    "34 St-Herald Sq",
    "42 St-Bryant Park",
    "47-50 Sts-Rockefeller Ctr",
    "5 Av/53 St",
    "Lexington Av/53 St"
};

const int START_INDEX = 0;

const int END_INDEX = sizeof(STATIONS)/sizeof(std::string) - 1;

struct EventComparator {
  bool operator()(const Event * lhs,
    const Event * rhs) const {
    if (lhs -> get_timestamp() == rhs -> get_timestamp()) {
      return lhs -> get_priority_within_timestamp() > rhs -> get_priority_within_timestamp();
    }
    return lhs -> get_timestamp() > rhs -> get_timestamp();
  }
};

void print(std::string input_string, std::priority_queue < Event * , std::vector < Event * > , EventComparator > time_copy) { //passing by value
    std::cout << input_string << std::endl;
    while (!time_copy.empty()) {
        Event * event = time_copy.top();
        time_copy.pop();
        std::cout << event -> get_timestamp() << " " << event -> get_priority_within_timestamp() << " " << event -> get_event_type() << std::endl;
    }
}

void print(std::string input_string, std::map <std::string,std::vector < Person >> waiting_list_copy) { //passing by value
    std::cout << input_string << std::endl;
    for (int i = 0; i < sizeof(STATIONS)/sizeof(std::string); i++) {
        std::cout << STATIONS[i] <<"\n";
        std::vector < Person > people = waiting_list_copy[STATIONS[i]];
        for (int j = 0; j < people.size(); j++) {
            std::cout << "\t" << people[j].get_end_stop() << std::endl;
        }
    }
}

int main() {
  
  std::priority_queue < Event * , std::vector < Event * > , EventComparator > time;
  time = std::priority_queue < Event * , std::vector < Event * > , EventComparator > ();

  std::map <std::string,std::vector < Person >> waiting_list = std::map <std::string,std::vector < Person >>();
  
  for (int i = 0; i < sizeof(STATIONS)/sizeof(std::string); i++) {
    waiting_list[STATIONS[i]] = std::vector < Person >();
  }
  
  for (int i = 0; i< INIT_PASSENGER_EVENTS; i++){
      int start_station_index = random(START_INDEX, END_INDEX-1);
      int end_station_index = random(start_station_index+1, END_INDEX);
      time.push(createPassengerEvent(random(START_TIME, END_TIME),
                                      2, 
                                      STATIONS[start_station_index],
                                      &waiting_list[STATIONS[start_station_index]],
                                      STATIONS[end_station_index]));
  }

  while (!time.empty()) {
    Event * event = time.top();
    if (event->get_event_type() == "PassengerEvent") {
      std::cout<<event->execute();
    }
    else if (event-> get_event_type() == "SubwayCarEvent"){

    }
    else{
      //Create new exception called event not found
      throw EventNotFoundException();
    }

    delete event;
    time.pop();
  }

  print("Event Queue after loop: ", time);
  std::cout << "----------------" << std::endl;
  print("Waiting List after loop: ", waiting_list);
  return 0;
}