#ifndef MANAGER_H
#define MANAGER_H

using namespace std;

class Manager {
public:
    Manager(int city);
    ~Manager(); 
    int getCity() const;

private:
    int city; 
};

#endif // MANAGER_H
