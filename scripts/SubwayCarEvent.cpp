#include "headers/SubwayCarEvent.h"
#include <string>
#include "headers/Route.h"
#include <vector>
#include "headers/SubwayCar.h"

SubwayCarEvent::SubwayCarEvent(int timestamp, 
                            int priority_within_stamp, 
                            std::string next_stop, 
                            SubwayCar* car,
                            Route* route
                            ) : 
                            Event(timestamp, priority_within_stamp), 
                            next_stop(next_stop), 
                            car(car),
                            route(route){};

std::string SubwayCarEvent::get_event_type() const{ 
    return "Subway Car Event"; };

Route* SubwayCarEvent::get_route(){
    return this->route;
};

SubwayCar * SubwayCarEvent::get_car(){
    return this->car;
};

std::string SubwayCarEvent::execute(){
    return "Here";
};