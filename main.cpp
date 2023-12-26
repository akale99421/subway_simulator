#include <queue>

#include <iostream>

#include <string>

#include "scripts/headers/Event.h"

#include "scripts/headers/PassengerEvent.h"

#include "scripts/headers/SubwayCarEvent.h"

#include "scripts/headers/EventFactory.h"

#include <vector>

#include <map>

#include "scripts/headers/Person.h"

#include "scripts/headers/Exceptions.h"

#include <random>

const int INIT_PASSENGER_EVENTS = 100;

const int NUMBER_OF_CARS = 5;

const int TIME_BETWEEN_LAUNCH = 15;

const int START_TIME = 0;

const int END_TIME = 1440;

std::random_device rand_dev;
std::mt19937 generator(rand_dev());

template<typename T>
T random(T start, T end) {
    std::uniform_int_distribution<T> distr(start, end);
    return distr(generator);
}


const std::vector<std::string> UPTOWN_F_STATIONS = {
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

/* this is from copilot. Surprisingly accurate
const std::map<std::string, std::string[]> UPTOWN_F_STATIONS_MAP = {
    {"Delancey St-Essex St", {"F", "M", "J", "Z"}},
    {"Broadway-Lafayette St", {"F", "M", "J", "Z", "6", "B", "D"}},
    {"W 4 St-Washington Sq", {"F", "M", "A", "C", "E", "B", "D"}},
    {"14 St-Union Sq", {"F", "M", "L", "N", "Q", "R", "4", "5", "6"}},
    {"23 St", {"F", "M", "N", "R"}},
    {"34 St-Herald Sq", {"F", "M", "B", "D", "N", "Q", "R"}},
    {"42 St-Bryant Park", {"F", "M", "B", "D"}},
    {"47-50 Sts-Rockefeller Ctr", {"F", "M", "B", "D"}},
    {"5 Av/53 St", {"F", "M", "E"}},
    {"Lexington Av/53 St", {"F", "M", "E"}}
}; */



const int START_INDEX = 0;

const int END_INDEX = UPTOWN_F_STATIONS.size() - 1;

struct EventComparator {
  bool operator()(const Event * lhs,
    const Event * rhs) const {
    if (lhs -> get_timestamp() == rhs -> get_timestamp()) {
      return lhs -> get_priority_within_timestamp() > rhs -> get_priority_within_timestamp();
    }
    return lhs -> get_timestamp() > rhs -> get_timestamp();
  }
};

void print(std::string input_string, 
            std::priority_queue < Event * , std::vector < Event * > , EventComparator > time_copy) { //passing by value
    std::cout << input_string << std::endl;
    while (!time_copy.empty()) {
        Event * event = time_copy.top();
        time_copy.pop();
        std::cout << event -> get_timestamp() << " " << event -> get_priority_within_timestamp() << " " << event -> get_event_type() << std::endl;
    }
}

void print(std::string input_string, 
            std::map <std::string,std::queue < Person* >> waiting_list_copy) { //passing by value
    std::cout << input_string << std::endl;
    for (int i = 0; i < UPTOWN_F_STATIONS.size() ; i++) {
        std::cout << UPTOWN_F_STATIONS[i] <<"\n";
        std::queue < Person* > people = waiting_list_copy[UPTOWN_F_STATIONS[i]];
        for (int j = 0; j < people.size(); j++) {
            std::cout << "\t" << people.front()->get_end_stop() << std::endl;
            people.pop();
        }
    }
}

int main() {

  Route uptown_f = Route(UPTOWN_F_STATIONS, "Uptown F");
  
  std::priority_queue < Event * , std::vector < Event * > , EventComparator > time;
  time = std::priority_queue < Event * , std::vector < Event * > , EventComparator > ();

  std::map <std::string,std::queue < Person* >> waiting_list = std::map <std::string,std::queue < Person* >>();
  
  for (int i = 0; i < UPTOWN_F_STATIONS.size() ; i++) {
    waiting_list[UPTOWN_F_STATIONS[i]] = std::queue < Person* >();
  }
  
  for (int i = 0; i< INIT_PASSENGER_EVENTS; i++){
      int start_station_index = random(START_INDEX, END_INDEX-1);
      int end_station_index = random(start_station_index+1, END_INDEX);
      time.push(createPassengerEvent(random(START_TIME, END_TIME),
                                      2, 
                                      UPTOWN_F_STATIONS[start_station_index],
                                      UPTOWN_F_STATIONS[end_station_index]));
  }

  for (int i = 0; i< NUMBER_OF_CARS; i++){
      int bus_start = START_TIME + i*TIME_BETWEEN_LAUNCH;
      int bus_end = START_TIME + (1+i)*TIME_BETWEEN_LAUNCH -1; //simultaneous launching is definitely possible by we limit it
      time.push(createSubwayCarEvent(random(bus_start, bus_end),
                                      1, 
                                      UPTOWN_F_STATIONS[START_INDEX],
                                      new SubwayCar(100),
                                      &uptown_f));
  }

  print("Event Queue before loop: ", time);
  std::cout << "----------------" << std::endl;
  print("Waiting List before loop: ", waiting_list);

  while (!time.empty()) {
    Event * event = time.top();
    if (event->get_event_type() == "Passenger Event") {
      PassengerEvent* passengerEvent = dynamic_cast<PassengerEvent*>(event); //I don't love this.
      waiting_list[passengerEvent->get_start_stop_name()].push(passengerEvent->execute());
    }
    else if (event-> get_event_type() == "Subway Car Event"){
      
      
      std::cout << "";
    }
    else{
      //Create new exception called event not found
      throw EventNotFoundException();
    }
    time.pop();
    delete event;
    
  }

  print("Event Queue after loop: ", time);
  std::cout << "----------------" << std::endl;
  print("Waiting List after loop: ", waiting_list);
  for (int i = 0; i < UPTOWN_F_STATIONS.size() ; i++) {
      std::queue<Person*>* clear_list = &waiting_list[UPTOWN_F_STATIONS[i]];
      while (!clear_list->empty()) {
          Person * person_to_delete = clear_list->front();
          clear_list->pop();
          delete person_to_delete;

      }

  }
  return 0;
}