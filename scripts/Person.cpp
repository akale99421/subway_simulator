#include "headers/Person.h"

Person::Person() : end_stop() {};
Person::Person(std::string name) : end_stop(name){};
std::string Person::get_end_stop(){
            return this->end_stop;
};
std::string Person::get_start_stop(){
            return this->start_stop;
};