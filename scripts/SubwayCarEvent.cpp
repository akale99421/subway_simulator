#include "headers/SubwayCarEvent.h"
#include <string>
#include <vector>
#include "headers/SubwayCar.h"

/*SubwayCarEvent::SubwayCarEvent(int timestamp, 
                            int priority_within_stamp, 
                            std::string next_stop, 
                            SubwayCar* car) : Event(timestamp, priority_within_stamp), 
                            next_stop(next_stop), car(car) {};*/

std::string SubwayCarEvent::execute(){
    return "Here";
};

int SubwayCarEvent::reschedule(int add_to){
    this->timestamp = this->timestamp + add_to;
    return this->timestamp;
};