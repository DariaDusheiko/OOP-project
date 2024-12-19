#ifndef GARAGE_H
#define GARAGE_H

using namespace std;

class Garage {
public:
    Garage(int city);
    ~Garage(); 
    int getCity() const;

private:
    int city; 
};

#endif // GARAGE_H
