#include <iostream>
#include <string.h>
#include "modules.h"

using namespace std;


void Modules::setName(const string n){
    _Name = n;
}

void Modules::setDamage(const int d){
    _Damage = d;
}

void Modules::setAccurasy(const int a){
    _Accurasy = a;
}

void Modules::setFirerate(const int f){
    _Firerate = f;
}

void Modules::setWeight(const float w){
    _Weight = w;
}

void Modules::setAmmo(const int b){
    _Ammo = b;
}

string Modules::Name() const{
    return _Name;
}

int Modules::Damage() const{
    return _Damage;
}

int Modules::Accurasy() const{
    return _Accurasy;
}

int Modules::Firerate() const{
    return _Firerate;
}

float Modules::Weight() const{
    return _Weight;
}

int Modules::Ammo() const{
    return _Ammo;
}

