#include <queue>
#include <iostream>
#include <string>
#include "scripts/headers/Event.h"

template <class T1, class T2>
void print(std::string input_string,std::priority_queue<Event<T1,T2>> time) {
    std::cout << input_string << std::endl;
    while (!time.empty()) {
        Event<T1,T2> event = time.top();
        time.pop();
        std::cout << event.get_timestamp() << " " << event.get_priority_within_timestamp() << std::endl;
    }
}

int main(){
    std::priority_queue<Event<int, char>> time = std::priority_queue<Event<int, char>>();
    Event<int,char> event = Event<int,char>(1, 'b');
    Event<int,char> event2 = Event<int,char>();
    event2.set_data(3, 'd');
    Event<int,char> event3 = Event<int,char>(3, 'q');
    Event<int,char> event4 = Event<int,char>(1,'v');
    time.push(event);
    time.push(event2);
    time.push(event3);
    time.push(event4);
    print("Before", time);
    time.pop();
    print("After", time);

    time.push(Event<int,char>(100,'z'));
    print("After push", time);
    time.push(Event<int,char>(3,'q'));
    print("After push", time);

}