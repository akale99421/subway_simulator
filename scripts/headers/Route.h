#include <string>
#include <vector>
#ifndef ROUTE_H
#define ROUTE_H


class Route {
    public:
        Route(std::vector<std::string> list_of_stops, std::string route_name);
        std::string get_route_name();
        std::vector<std::string> get_stop_list();
        int get_route_length();
    private:
        int route_length;
        std::string route_name;
        std::vector<std::string> list_of_stops;

};

#endif