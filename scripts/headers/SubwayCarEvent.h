// Event.h
// Abstract event class that will be extened by events scheduled on the priority queue
#include <string>
#include "Event.h"
#include "SubwayCar.h"
#include "Route.h"
#ifndef SUBWAY_CAR_EVENT_H
#define SUBWAY_CAR_EVENT_H

class SubwayCarEvent : public Event {
public:
    SubwayCarEvent(int timestamp, 
            int priority_within_stamp, 
            std::string next_stop, 
            SubwayCar* car,
            Route* route);
    std::string get_event_type() const override;
    std::string execute();
    Route* get_route();
    SubwayCar * get_car();

private:
    std::string next_stop;
    Route* route;
    SubwayCar * car;
};

#endif