#include "headers/EventFactory.h"
#include "vector"
#include "headers/Person.h"

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp) {
    return new PassengerEvent(timestamp, priority_within_stamp);
}

PassengerEvent* createPassengerEvent() {
    return new PassengerEvent();
}

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp, std::string start_stop_name, std::vector < Person >* start_stop, std::string end_stop) {
    return new PassengerEvent(timestamp, priority_within_stamp, start_stop_name, start_stop, end_stop);
}
