#include "headers/EventFactory.h"
#include "vector"
#include "headers/Person.h"
#include "headers/SubwayCarEvent.h"

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp) {
    return new PassengerEvent(timestamp, priority_within_stamp);
}

PassengerEvent* createPassengerEvent() {
    return new PassengerEvent();
}

PassengerEvent* createPassengerEvent(int timestamp, 
                                    int priority_within_stamp, 
                                    const std::string start_stop_name, 
                                    const std::string end_stop) {
    return new PassengerEvent(timestamp, priority_within_stamp, start_stop_name, end_stop);
}

SubwayCarEvent* createSubwayCarEvent(int timestamp, 
                                    int priority_within_stamp, 
                                    const std::string next_stop, 
                                    SubwayCar* car,
                                    Route* route) {
    return new SubwayCarEvent(timestamp, priority_within_stamp, next_stop, car, route);
}