#include "Device.h"

Device::Device(int city) : city(city) {}

Device::~Device() {} 

int Device::getCity() const {
    return city;
}
