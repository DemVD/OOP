#include <math.h>
#include <iostream>
#include "geometricfigure.h"


void GeometricFigure::setA(float a){ // установить одну из сторон
    A = a;
}

float GeometricFigure::getA(){ // получить одну из сторон
    return A;
}

void GeometricFigure::setB(float b){ // установить другую из сторон
    B = b;
}

float GeometricFigure::getB(){ // получить другую из сторон
    return B;
}

float GeometricFigure::perimCalc(){ // вычисление периметра
    return A+A+B+B;
}

float GeometricFigure::areaCalc(){ // вычисление площади
    return A*B;
}


void Triangle::setC(float c){ // установить сторону С
    C = c;
}

float Triangle::getC(){ // получить сторону С
    return C;
}

float Triangle::calcHa(){ // вычислить высоту на стороне а
    float hP = perim()/2; // полупериметр
    float H = (2/getA())*sqrt(hP*(hP-getA())*(hP-getB())*(hP-getC()));
    return H; // высота на стороне а
}

float Triangle::perim(){ // вычисление периметра ПЕРЕОПРЕДЕЛЕНИЕ
    if (getA()+getB()>C || getA()+C>getB() || getB()+C>getA()){
        return getA()+getB()+C;
    }
    else{
        return 0;
    }
}

float Triangle::area(){ // вычисление площади ПЕРЕОПРЕДЕЛЕНИЕ

    if (getA()+getB()>C || getA()+C>getB() || getB()+C>getA()){
        return (getA()*calcHa())/2;
    }
    else{
        return 0;
    }
}


float Circle::perim(){
    return 2*M_PI*getA();
}

float Circle::area(){
    return M_PI*(getA()*getA());
}

