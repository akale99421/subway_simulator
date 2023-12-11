#include "PassengerEvent.h"

#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

PassengerEvent* createPassengerEvent(int timestamp, int priority_within_stamp);

PassengerEvent* createPassengerEvent();
#endif