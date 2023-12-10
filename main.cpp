#include <queue>
#include <iostream>
#include <string>
#include "scripts/headers/Event.h"
#include <vector>
Event* createPassengerEvent(int timestamp, int priority_within_stamp); // This is forward declaration!!!!
Event* createPassengerEvent();

struct EventComparator {
    bool operator()(const Event* lhs, const Event* rhs) const {
        if (lhs->get_timestamp() == rhs->get_timestamp()) {
            return lhs->get_priority_within_timestamp() > rhs->get_priority_within_timestamp();
        }
        return lhs->get_timestamp() > rhs->get_timestamp();
    }
};


void print(std::string input_string,std::priority_queue<Event*, std::vector<Event*>, EventComparator> time) { //passing by value
    std::cout << input_string << std::endl;
    while (!time.empty()) {
        Event* event = time.top();
        time.pop();
        std::cout << event->get_timestamp() << " " << event->get_priority_within_timestamp() << std::endl;
    }
}

int main(){
    std::priority_queue<Event*, std::vector<Event*>, EventComparator> time; time = std::priority_queue<Event*,std::vector<Event*>,EventComparator>();
    Event* event = createPassengerEvent(1, 10);
    Event* event2 = createPassengerEvent();
    event2->set_data(3, 11);
    Event* event3 = createPassengerEvent(3, 15);
    Event* event4 = createPassengerEvent(1,12);
    time.push(event);
    time.push(event2);
    time.push(event3);
    time.push(event4);
    print("Before", time);
    std::cout << time.top()->execute();
    time.pop();
    print("After", time);
    std::cout << time.top()->execute();
    time.pop();
    std::cout << time.top()->execute();
    time.pop();
    std::cout << time.top()->execute();
    time.pop();
    print("After", time);

}