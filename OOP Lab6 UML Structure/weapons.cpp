#include <iostream>
#include <string.h>
#include "weapons.h"

using namespace std;


void Weapons::Fire(){ // выстрелить
    _Ammo--; // - 1 патрон после выстрела
    if(_Ammo==0){ // заклинить если кончились патроны
        Jam(); // вызов функции заклинивания
    }
}

void Weapons::Jam(){ // заклинить
    _Firerate = 0; // скорострельность 0 выстрелов в минуту
}

void Weapons::Reload(){ // перезарядить
    _Ammo = _AbsAmmo; // поменять обойму в соотв. с оружием
    _Firerate = _AbsFirerate; // вернуть скорострельность в соотв. с оружием
}

void Weapons::setName(const string s){
    _Name = s;
}

void Weapons::setDamage(const int d){
    _Damage = d;
}

void Weapons::setAccurasy(const int a){
    _Accurasy = a;
}

void Weapons::setFirerate(const int f){
    _Firerate = f;
}

void Weapons::setWeight(const float gw){
    _Weight = gw;
}

void Weapons::setAmmo(const int b){
    _Ammo = b;
}

string Weapons::Name() const{
    return _Name;
}

int Weapons::Damage() const{
    return _Damage;
}

int Weapons::Accurasy() const{
    return _Accurasy;
}

int Weapons::Firerate() const{
    return _Firerate;
}

float Weapons::Weight() const{
    return _Weight;
}

int Weapons::Ammo() const{
    return _Ammo;
}

