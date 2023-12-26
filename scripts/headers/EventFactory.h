#include "PassengerEvent.h"
#include "SubwayCarEvent.h"
#include "Route.h"
#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp);

PassengerEvent* createPassengerEvent();

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp,std::string start_stop_name, std::string end_stop);

SubwayCarEvent* createSubwayCarEvent(int timestamp, int priority_within_stamp, std::string next_stop, SubwayCar* car, Route* route);

#endif