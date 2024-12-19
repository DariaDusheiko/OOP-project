#ifndef DEVICE_H
#define DEVICE_H

using namespace std;

class Device {
public:
    Device(int city);
    virtual ~Device(); 
    int getCity() const;

protected:
    int city; 
};

#endif // DEVICE_H
