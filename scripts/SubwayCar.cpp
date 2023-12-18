#include <string>
#include <map>
#include "headers/SubwayCar.h"

SubwayCar::SubwayCar(int capacity) : capacity(capacity) {};
SubwayCar::~SubwayCar() {};
int SubwayCar::get_capacity() const { return capacity; };
int SubwayCar::get_num_passengers() const { return passengers.size(); }; //change this logic to iterate

void SubwayCar::add_passengers(std::string stop_name, int number_passengers) {
    passengers[stop_name] = number_passengers;
};

void SubwayCar::unload_passengers(std::string stop_name) {
    passengers[stop_name] = 0;
};