#ifndef TIMECLASS_H
#define TIMECLASS_H
#include <math.h>
#include <vector>
#include <iostream>
#include "header.h"

using namespace std;


class Time{
private:
    int Hours=0;
    int Minutes=0;
    int Seconds=0;
public:
    Time(int H=0, int M=0, int S=0); //constructor with param-s

    int setHours(int Hnum); //set hours

    int setMinutes(int Mnum); //set minutes, converts to hours if M>59

    int setSeconds(int Snum); //set seconds,converts to hrs and mns if S>59

    int getHours(); //return hours

    int getMinutes(); //return minutes

    int getSeconds(); //return seconds

    string convToStr(); //return string with time

    void addTime(int Hours=0, int Minutes=0, int Seconds=0); // adds time

    int convToSecs(); // converts H and M to S.

    float convToMins(); // converts H and S to M, FP result.

    float convToHous(); // converts M and S to H. FP result.
};


#endif // TIMECLASS_H
