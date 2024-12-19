#include "Garage.h"

Garage::Garage(int city) : city(city) {}

Garage::~Garage() {} 
int Garage::getCity() const {
    return city;
}
