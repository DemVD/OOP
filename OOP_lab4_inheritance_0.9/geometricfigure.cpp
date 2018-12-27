#include <math.h>
#include <iostream>
#include "geometricfigure.h"


GeometricFigure::GeometricFigure(){ // конструктор умолчания

}

GeometricFigure::GeometricFigure(const float A, const float B){
    _A = A;
    _B = B;
}

void GeometricFigure::setA(const float A){ // установить одну из сторон
    _A = A;
}

float GeometricFigure::A() const{ // получить одну из сторон
    return _A;
}

void GeometricFigure::setB(const float B){ // установить другую из сторон
    _B = B;
}

float GeometricFigure::B() const{ // получить другую из сторон
    return _B;
}

float GeometricFigure::perim() const{ // вычисление периметра
    return _A+_A+_B+_B;
}

float GeometricFigure::area() const{ // вычисление площади
    return _A*_B;
}


Rectangle::Rectangle() :GeometricFigure (){

}


Triangle::Triangle() :GeometricFigure(){

}

Triangle::Triangle(const float A, const float B, const float C) :GeometricFigure(A,B){
    _A = A;
    _B = B;
    _C = C;
}

void Triangle::setC(const float c){ // установить сторону С
    _C = c;
}

float Triangle::C() const{ // получить сторону С
    return _C;
}

float Triangle::calcHa() const{ // вычислить высоту на стороне а
    float hP = perim()/2; // полупериметр
    float H = (2/A())*sqrt(hP*(hP-A())*(hP-B())*(hP-C()));
    return H; // высота на стороне а
}

float Triangle::perim() const{ // вычисление периметра ПЕРЕОПРЕДЕЛЕНИЕ
    if (A()+B()>_C || A()+_C>B() || B()+_C>A()){
        return A()+B()+_C;
    }
    else{
        return 0;
    }
}

float Triangle::area() const{ // вычисление площади ПЕРЕОПРЕДЕЛЕНИЕ

    if (A()+B()>_C || A()+_C>B() || B()+_C>A()){
        return (A()*calcHa())/2;
    }
    else{
        return 0;
    }
}


Circle::Circle() :GeometricFigure(){ // нужно ли :GeometricFigure

}

Circle::Circle(float R) :GeometricFigure(){ //  :GeometricFigure() ?
    _R = R;
}

void Circle::setR(const float R){
    _R = R;
}

float Circle::R() const{
    return _R;
}

float Circle::perim() const{
    return 2*M_PI*_R;
}

float Circle::area() const{
    return M_PI*(_R*_R);
}
