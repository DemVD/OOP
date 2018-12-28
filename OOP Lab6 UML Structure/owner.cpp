#include <iostream>
#include <string.h>
#include "owner.h"

using namespace std;


void Owner::use_gun(const string gun_name){
    if(_license){
        set_primary_weapon(gun_name);
    }
    else{
        set_primary_weapon("Get a license!");
    }
}

void Owner::set_first_name(const string fn){
    _first_name = fn;
}

void Owner::set_last_name(const string ln){
    _last_name = ln;
}

void Owner::set_license(const bool lc){
    _license = lc;
}

void Owner::set_primary_weapon(const string gn){
    _primary_weapon = gn;
}

string Owner::firstName() const{
    return _first_name;
}

string Owner::lastName() const{
    return _last_name;
}

bool Owner::license() const{
    return _license;
}

string Owner::primaryWeapon() const{
    return _primary_weapon;
}
