#include <queue>
#include <iostream>
#include <string>
#include "scripts/headers/Event.h"

void print(std::string input_string,std::priority_queue<Event> time) {
    std::cout << input_string << std::endl;
    while (!time.empty()) {
        Event event = time.top();
        time.pop();
        std::cout << event.get_timestamp() << " " << event.get_priority_within_timestamp() << std::endl;
    }
}

int main(){
    std::priority_queue<Event> time = std::priority_queue<Event>();
    Event event = Event(1, 'b');
    Event event2 = Event();
    event2.set_data(3, 'd');
    Event event3 = Event(3, 'q');
    Event event4 = Event(1,'v');
    time.push(event);
    time.push(event2);
    time.push(event3);
    time.push(event4);
    print("Before", time);
    time.pop();
    print("After", time);

    time.push(Event(100,'z'));
    print("After push", time);
    time.push(Event(3,'q'));
    print("After push", time);

}