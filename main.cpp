#include <queue>

#include <iostream>

#include <string>

#include "scripts/headers/Event.h"

#include "scripts/headers/EventFactory.h"

#include <vector>

#include <map>

#include "scripts/headers/Person.h"

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
  
  Event * event = createPassengerEvent(7, 
                                        2, 
                                        "Delancey St-Essex St",
                                        &waiting_list["Delancey St-Essex St"],
                                        "23 St");

  time.push(event);
  std::cout << sizeof(*event);
  
  print("Event Queue before loop: ", time);
  std::cout << "----------------" << std::endl;
  print("Waiting List before loop: ", waiting_list);
  std::cout << "----------------" << std::endl;


  while (!time.empty()) {
    Event * event = time.top();
    std::cout<<event->execute();
    time.pop();
    delete event;
  }

  print("Event Queue after loop: ", time);
  std::cout << "----------------" << std::endl;
  print("Waiting List after loop: ", waiting_list);
}