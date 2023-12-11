// Event.h
// Abstract event class that will be extened by events scheduled on the priority queue
#include <string>
#include "Event.h"
#include "vector"
#include "Person.h"
#ifndef PASSENGER_EVENT_H
#define PASSENGER_EVENT_H

class PassengerEvent : public Event {
public:
    PassengerEvent();
    std::string execute() override;
    PassengerEvent(int timestamp, int priority_within_stamp);
    PassengerEvent(int timestamp, int priority_within_stamp, std::string start_stop_name,
                    std::vector < Person >* start_stop, std::string end_stop);
private:
    std::vector < Person > * start_stop;
    std::string start_stop_name;
    std::string end_stop;
};

#endif