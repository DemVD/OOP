#include <QCoreApplication>
#include <iostream>
#include "geometricfigure.h"

using namespace std;


int main(){
    Rectangle r1;
    r1.setA(5);
    r1.setB(5);
    cout<<"Rectangle(5x5) area: "<<r1.areaCalc()<<endl;
    cout<<"Rectangle(5x5) perim: "<<r1.perimCalc()<<endl;

    Triangle t1;
    t1.setA(3);
    t1.setB(4);
    t1.setC(5);
    cout<<"triangle height: "<<t1.calcHa()<<endl;
    cout<<"Triangle("<<t1.getA()<<","<<t1.getB()<<","<<t1.getC()
       <<") area: "<<t1.area()<<endl;
    cout<<"perim: "<<t1.perim()<<endl;

    Circle c1;
    c1.setA(6);
    cout<<"Circle area: "<<c1.area()<<endl;
    cout<<"Citcle perim: "<<c1.perim()<<endl;
}
