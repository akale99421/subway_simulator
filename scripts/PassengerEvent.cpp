#include "headers/PassengerEvent.h"
#include <string>
#include <vector>
#include "headers/Person.h"

PassengerEvent::PassengerEvent(int timestamp, int priority_within_stamp) : Event(timestamp, priority_within_stamp) {};

PassengerEvent::PassengerEvent() : Event() {};

PassengerEvent::PassengerEvent(int timestamp, int priority_within_stamp, 
                                std::string start_stop_name, 
                                std::vector < Person >* start_stop, 
                                std::string end_stop) : Event(timestamp, priority_within_stamp), start_stop_name(start_stop_name),start_stop(start_stop), end_stop(end_stop) {};

std::string PassengerEvent::execute(){
        this->start_stop->push_back(Person(this->end_stop));
        return "Created Passenger at time " +
            std::to_string(get_timestamp()) + 
            " with priority " +
             std::to_string(get_priority_within_timestamp()) +
             " at stop " + 
             this->start_stop_name
             + " heading to stop " + this->end_stop
             + "\n";
};