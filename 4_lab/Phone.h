#ifndef PHONE_H
#define PHONE_H

#include "Device.h"

class Phone : public Device {
public:
    Phone(int city);
    ~Phone(); 
};

#endif // PHONE_H
