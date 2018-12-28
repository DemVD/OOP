#ifndef OWNER_H
#define OWNER_H
#include <iostream>
#include <string.h>

using namespace std;


class Owner{
private:
    string _first_name;
    string _last_name;
    bool _license = 0;
    string _primary_weapon = "None";
public:
    void use_gun(const string gun_name);
    void set_first_name(const string fn);
    void set_last_name(const string ln);
    void set_license(const bool lc);
    void set_primary_weapon(const string gn);
    string firstName() const;
    string lastName() const;
    bool license() const;
    string primaryWeapon() const;
};


#endif // OWNER_H
