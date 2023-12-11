#include "PassengerEvent.h"

#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp);

PassengerEvent* createPassengerEvent();

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp,std::string start_stop_name, std::vector < Person >* start_stop, std::string end_stop);

#endif