// Event.h
// Abstract event class that will be extened by events scheduled on the priority queue
#include <string>
#include "Event.h"
#include "SubwayCar.h"
#ifndef SUBWAY_CAR_EVENT_H
#define SUBWAY_CAR_EVENT_H

class SubwayCarEvent : public Event {
public:
    //SubwayCarEvent(int timestamp, int priority_within_stamp, std::string next_stop, SubwayCar* car);
    ~SubwayCarEvent();
    std::string get_event_type() const override { return "Subway Car Event"; };
    int reschedule(int new_timestamp);
    std::string execute();
private:
    std::string next_stop;
    SubwayCar * car;
};

#endif