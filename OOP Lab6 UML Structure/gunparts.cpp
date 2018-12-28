#include <iostream>
#include <string.h>
#include "gunparts.h"

using namespace std;


void GunParts::setMaterial(const string s){
    _material = s;
}

void GunParts::setSupplier(const string s){
    _supplier = s;
}

void GunParts::setMuzzle(const string s){
    _muzzle = s;
}

void GunParts::setGunbox(const string s){
    _gunbox = s;
}

void GunParts::setTotalWeight(const double TW){
    _totalWeight = TW;
}

string GunParts::material() const{
    return _material;
}

string GunParts::supplier() const{
    return _supplier;
}

string GunParts::muzzle() const{
    return _muzzle;
}

string GunParts::gunbox() const{
    return _gunbox;
}

double GunParts::totalWeight() const{
    return _totalWeight;
}


