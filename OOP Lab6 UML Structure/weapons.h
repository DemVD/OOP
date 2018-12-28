#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>
#include <string.h>
#include "gunparts.h" // КОМПОЗИЦИЯ
#include "modules.h" // АГРЕГАЦИЯ

using namespace std;


class Weapons :public GunParts{
private:
    string _Name = "template";
    int _Damage = 1;
    int _Accurasy = 1;
    int _Firerate = 1;
    float _Weight = 0;
    int _Ammo = 1;
protected:
    int _AbsFirerate = 1;
    int _AbsAmmo = 30;
    void Fire();
    void Jam();
    void Reload();
public:
    void setName(const string s);
    void setDamage(const int d);
    void setAccurasy(const int a);
    void setFirerate(const int f);
    void setWeight(const float gw);
    void setAmmo(const int b);
    string Name() const;
    int Damage() const;
    int Accurasy() const;
    int Firerate() const;
    float Weight() const;
    int Ammo() const;
};



#endif // WEAPONS_H
