#include "headers/EventFactory.h"

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp) {
    return new PassengerEvent(timestamp, priority_within_stamp);
}

PassengerEvent* createPassengerEvent() {
    return new PassengerEvent();
}
