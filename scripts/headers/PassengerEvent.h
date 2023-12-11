// Event.h
// Abstract event class that will be extened by events scheduled on the priority queue
#include <string>
#include "Event.h"
#ifndef PASSENGER_EVENT_H
#define PASSENGER_EVENT_H

class PassengerEvent : public Event {
public:
    PassengerEvent();
    std::string execute() override;
    PassengerEvent(int timestamp, int priority_within_stamp);
};

Event* createPassengerEvent(int timestamp, int priority_within_stamp);
Event* createPassengerEvent();

#endif