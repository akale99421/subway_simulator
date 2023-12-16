#include <queue>

#include <iostream>

#include <string>

#include "scripts/headers/Event.h"

#include "scripts/headers/EventFactory.h"

#include <vector>

#include <map>

#include "scripts/headers/Person.h"

#include <random>

const std::string F_STATIONS[10] = {
    "Delancey St-Essex St",
    "Broadway-Lafayette St",
    "W 4 St-Washington Sq",
    "14 St-Union Sq",
    "23 St",
    "34 St-Herald Sq",
    "42 St-Bryant Park",
    "47-50 Sts-Rockefeller Ctr",
    "5 Av/53 St",
    "Lexington Av/53 St"
};




int main(){
std::map <std::string,std::vector < Person >*> F_TRAIN_UPTOWN = std::map <std::string,std::vector < Person >*>();
  
  for (int i = 0; i < sizeof(F_STATIONS)/sizeof(std::string); i++) {
    F_TRAIN_UPTOWN[F_STATIONS[i]] = new std::vector < Person >;
  }

  F_TRAIN_UPTOWN["Delancey St-Essex St"] -> push_back(Person("Lexington Av/53 St"));

  std::vector < Person >* location_of_del =  F_TRAIN_UPTOWN["Delancey St-Essex St"];
  std::vector < Person > pers= *location_of_del;
  std::cout<<(*location_of_del)[0].get_end_stop()<<std::endl;

  for (int i = 0; i < sizeof(F_STATIONS)/sizeof(std::string); i++) {
    delete F_TRAIN_UPTOWN[F_STATIONS[i]];  }
  return 0;
}