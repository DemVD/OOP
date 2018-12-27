#include <QCoreApplication>
#include <iostream>
#include "geometricfigure.h"

using namespace std;


int main(){
    //изначальная проверка динамического полиморфизма!!
    vector<GeometricFigure*> GFs; // список фигур с указателем на виды фигур
    Rectangle *r1 = new Rectangle(5,5);
    Triangle *t1 = new Triangle(5,5,5);
    Circle *c1 = new Circle(5);
    GFs.push_back(r1);
    GFs.push_back(t1);
    GFs.push_back(c1);

    //Rectangle
    GFs[0]->setA(4); // when I write '.' it autocorrects '->'
    GFs[0]->setB(5);
    cout<<"Rectangle(5x5) area: "<<GFs[0]->area()<<endl;
    cout<<"Rectangle(5x5) perim: "<<GFs[0]->perim()<<endl;

    //Triangle
    GFs[1]->setA(3);
    GFs[1]->setB(4);
    GFs[1]->setC(2); // как же быть..
    cout<<"triangle height: "<<GFs[1]->calcHa()<<endl;
    cout<<"Triangle("<<GFs[1]->A()<<","<<GFs[1]->B()<<","<<GFs[1]->C()
       <<") area: "<<GFs[1]->area()<<endl;
    cout<<"perim: "<<GFs[1]->perim()<<endl;

    //Circle
    GFs[2]->setR(6);
    cout<<"Circle area: "<<GFs[2]->area()<<endl;
    cout<<"Citcle perim: "<<GFs[2]->perim()<<endl;
}
