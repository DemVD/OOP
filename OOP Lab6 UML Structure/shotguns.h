#ifndef SHOTGUNS_H
#define SHOTGUNS_H
#include <iostream>
#include <string.h>
#include "weapons.h" // НАСЛЕДОВАНИЕ

using namespace std;


class Shotguns{
private:
    bool _pumpaction = 1;
    int _particleamm = 8;
public:
    void set_pumpaction(const bool val);
    void set_particleamm(const int particles);
    bool pumpaction() const;
    int particles() const;
};

#endif // SHOTGUNS_H
