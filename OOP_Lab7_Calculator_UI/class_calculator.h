#ifndef CLASS_CALCULATOR_H
#define CLASS_CALCULATOR_H
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;


class Calculator{
private:
    double _N1=0;
    double _N2=0;
    double _R=0;
public:
    void setN1(const double n);
    double N1() const;
    void setN2(const double n);
    double N2() const;
    void setR(const double r);
    double R() const;
    void ADD();
    void SUB();
    void MUL();
    void DIV();
    void POW();
    void SIN();
    void COS();
    void TAN();
    void LGE();
    void EXP();

};


#endif // CLASS_CALCULATOR_H
