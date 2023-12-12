#include <string>
#include <map>
#ifndef SUBWAY_CAR_H
#define SUBWAY_CAR_H


class SubwayCar {
    public:
        SubwayCar(int capacity);
        ~SubwayCar();
        int get_capacity() const;
        int get_num_passengers() const;
        void add_passengers(std::string stop_name, int number_passengers);
        void unload_passengers(std::string stop_name);
    private:
        int capacity;
        std::map <std::string,int> passengers;
};

#endif