#include "Manager.h"

Manager::Manager(int city) : city(city) {}

Manager::~Manager() {} 

int Manager::getCity() const {
    return city;
}
