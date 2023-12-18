#include <string>
#ifndef PERSON_H
#define PERSON_H


class Person {
    public:
        Person();
        Person(std::string start_stop, std::string end_stop);
        std::string get_end_stop();
        std::string get_start_stop();
    private:
        std::string start_stop;
        std::string end_stop;
};

#endif