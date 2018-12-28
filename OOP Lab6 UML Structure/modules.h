#ifndef MODULES_H
#define MODULES_H
#include <iostream>
#include <string.h>

using namespace std;


class Modules{
private:
    string _Name = "template";
    int _Damage = 0;
    int _Accurasy = 0;
    int _Firerate = 0;
    float _Weight = 0;
    int _Ammo = 0;
public:
    void setName(const string n);
    void setDamage(const int d);
    void setAccurasy(const int a);
    void setFirerate(const int f);
    void setWeight(const float w);
    void setAmmo(const int b);
    string Name() const;
    int Damage() const;
    int Accurasy() const;
    int Firerate() const;
    float Weight() const;
    int Ammo() const;
};


#endif // MODULES_H
