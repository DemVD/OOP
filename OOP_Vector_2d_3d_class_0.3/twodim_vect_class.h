#ifndef TWODIM_VECT_CLASS_H
#define TWODIM_VECT_CLASS_H
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class TwoDimVect{
public:
    vector <int> setPointCoords(int x1, int y1){
        pointCoords[0] = x1;
        pointCoords[1] = y1;
        return pointCoords;
    }

    vector <int> getPointCoords(){
        return pointCoords;
    }

    double getVectLen(vector <int> point0){
        double res;
        res = sqrt( pow(point0[0]*pointCoords[0],2)+pow(point0[1]*pointCoords[1],2) );
        return res;
    }

private:
    vector<int> pointCoords = {0,0}; //x1,y1
};

#endif // TWODIM_VECT_CLASS_H
