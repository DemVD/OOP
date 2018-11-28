#ifndef TIMECLASS_H
#define TIMECLASS_H
#include <math.h>
#include <vector>
#include <iostream>
#include "header.h"

using namespace std;


class Time{
public:
    int setHours(int Hnum){
        Hours = Hnum;
        return Hours;
    }

    int setMinutes(int Mnum){
        if(Mnum > 59){
            Hours += Mnum/60;
            Mnum -= 60*(Mnum/60);
            Minutes = Mnum;
        }
        return Minutes;
    }

    int setSeconds(int Snum){
        if(Snum > 59){
            Minutes += Snum/60;
            Snum -= 60*(Snum/60);
            Seconds = Snum;
        }
        if(Minutes > 59){
            Hours += Minutes/60;
            Minutes -= 60*(Minutes/60);
        }
        return Seconds;
    }

    int getHours(){
        return Hours;
    }

    int getMinutes(){
        return Minutes;
    }

    int getSeconds(){
        return Seconds;
    }

    vector<int> getTime(){
        vector<int> time = {Hours,Minutes,Seconds};
        return time;
    }

private:
    int Hours=0;
    int Minutes=0;
    int Seconds=0;
};


#endif // TIMECLASS_H
