#include "headers/Event.h"
#include <string>

class PassengerEvent : public Event {
public:
    PassengerEvent(int timestamp, int priority_within_stamp) : Event(timestamp, priority_within_stamp) {};
    PassengerEvent() : Event() {};
    std::string execute() override{
        return "Created Passenger at time " +
            std::to_string(get_timestamp()) + 
            " with priority " +
             std::to_string(get_priority_within_timestamp())
             + "\n";
    }
};

Event* createPassengerEvent(int timestamp, int priority_within_stamp) {
    return new PassengerEvent(timestamp, priority_within_stamp);
}

Event* createPassengerEvent() {
    return new PassengerEvent();
}