// Event.h
#ifndef EVENT_H
#define EVENT_H

template <class T1, class T2>
class Event {
public:
    Event(T1 timestamp, T2 priority_within_stamp) : timestamp(timestamp), priority_within_stamp(priority_within_stamp) {}
    Event() : timestamp(), priority_within_stamp() {}

    bool operator<(const Event& rhs) const {
        if (timestamp > rhs.timestamp) {
            return true;
        } else if (timestamp == rhs.timestamp) {
            return priority_within_stamp > rhs.priority_within_stamp;
        }
        return false;
    }

    void set_data(T1 timestamp, T2 priority_within_stamp) {
        this->timestamp = timestamp;
        this->priority_within_stamp = priority_within_stamp;
    }

    T1 get_timestamp() const { return timestamp; }
    T2 get_priority_within_timestamp() const { return priority_within_stamp; }

private:
    T1 timestamp;
    T2 priority_within_stamp;
};

#endif // EVENT_H
