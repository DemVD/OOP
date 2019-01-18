#include <iostream>
#include <cmath>
#include <string.h>
#include "class_calculator.h"

using namespace std;


void Calculator::setN1(const double n){ _N1 = n; }

double Calculator::N1() const{ return _N1; }

void Calculator::setN2(const double n){ _N2 = n; }

double Calculator::N2() const{ return _N2; }

void Calculator::setR(const double r){ _R = r; }

double Calculator::R() const{ return _R; }

void Calculator::ADD(){
    _R = _N1+_N2;
}

void Calculator::SUB(){
    _R=_N1-_N2;
}

void Calculator::MUL(){
    _R=_N1*_N2;
}

void Calculator::DIV(){
    _R=_N1/_N2;
}

void Calculator::POW(){
    _R=pow(_N1,_N2);
}

void Calculator::SIN(){
    _R=sin(_N1);
}

void Calculator::COS(){
    _R=cos(_N1);
}

void Calculator::TAN(){
    _R=tan(_N1);
}

void Calculator::LGE(){
    _R=log(_N1);
}

void Calculator::EXP(){
    _R=exp(_N1);
}

