#include <iostream>
#include <string.h>
#include "shotguns.h"

using namespace std;


void Shotguns::set_pumpaction(const bool val){
    _pumpaction = val;
}

void Shotguns::set_particleamm(const int particles){
    _particleamm = particles;
}

bool Shotguns::pumpaction() const{
    return _pumpaction;
}

int Shotguns::particles() const{
    return _particleamm;
}
