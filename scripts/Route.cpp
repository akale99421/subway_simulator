#include "headers/Route.h"

Route::Route(std::vector<std::string> list_of_stops, std::string route_name) : 
    list_of_stops(list_of_stops), 
    route_name(route_name) {
    this->route_length = list_of_stops.size();
};

std::string Route::get_route_name(){
    return this->route_name;
};

std::vector<std::string> Route::get_stop_list(){
    return this->list_of_stops;
};

int Route::get_route_length(){
    return this->route_length;
};