// Event.h
// Abstract event class that will be extened by events scheduled on the priority queue
#include <string>
#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    Event(int timestamp, int priority_within_stamp) : timestamp(timestamp), priority_within_stamp(priority_within_stamp) {}
    Event() : timestamp(), priority_within_stamp() {}

    void set_data(int timestamp, int priority_within_stamp) {
        this->timestamp = timestamp;
        this->priority_within_stamp = priority_within_stamp;
    }

    int get_timestamp() const { return timestamp; }
    int get_priority_within_timestamp() const { return priority_within_stamp; }

    virtual std::string execute() = 0;

private:
    int timestamp;
    int priority_within_stamp;
};

#endif // EVENT_H
