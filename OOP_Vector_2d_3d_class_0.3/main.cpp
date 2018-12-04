#include <QCoreApplication>
#include "twodim_vect_class.h"
#include "threedim_vect_class.h"
#include <vector>

using namespace std;


int main(){
    TwoDimVect Point1;
    TwoDimVect Point2;
    Point1.setPointCoords(5,5);
    Point2.setPointCoords(10,10);
    cout << "Point1 coords: " << endl;
    for(auto x:Point1.getPointCoords()){
        cout << "(" << x << ")" << endl;
    }
}
