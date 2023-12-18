#include "headers/PassengerEvent.h"
#include <string>
#include <vector>
#include "headers/Person.h"

PassengerEvent::PassengerEvent(int timestamp, int priority_within_stamp) : Event(timestamp, priority_within_stamp) {};

PassengerEvent::PassengerEvent() : Event() {};



PassengerEvent::PassengerEvent(int timestamp, int priority_within_stamp, 
                                std::string start_stop_name, 
                                std::string end_stop) : Event(timestamp, priority_within_stamp)
                                    , start_stop_name(start_stop_name)
                                    , end_stop(end_stop) {};
std::string PassengerEvent::get_start_stop_name() const {
    return start_stop_name;
}; 
Person* PassengerEvent::execute(){
        return new Person(start_stop_name, end_stop);
};