#include "headers/Person.h"

Person::Person() : end_stop() {};
Person::Person(std::string start_stop, std::string end_stop) : end_stop(end_stop), start_stop(start_stop){};
std::string Person::get_end_stop(){
            return this->end_stop;
};
std::string Person::get_start_stop(){
            return this->start_stop;
};