#ifndef GUNPARTS_H
#define GUNPARTS_H
#include <iostream>
#include <string.h>

using namespace std;


class GunParts{
private:
    string _material = "Stainless Steel";
    string _supplier = "IMI Israel Military Industries";
    string _muzzle = "Regular";
    string _gunbox = "Regular";
    double _totalWeight = 3.1415926;
public:
    void setMaterial(const string s);
    void setSupplier(const string s);
    void setMuzzle(const string s);
    void setGunbox(const string s);
    void setTotalWeight(const double TW);
    string material() const;
    string supplier() const;
    string muzzle() const;
    string gunbox() const;
    double totalWeight() const;
};

#endif // GUNPARTS_H
