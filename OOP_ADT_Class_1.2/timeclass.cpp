#include <math.h>
#include <vector>
#include <iostream>
#include "header.h"
#include "timeclass.h"

using namespace std;


    Time::Time(int H,int M,int S){ //constructor with param-s
        Hours = H;
        Minutes = M;
        Seconds = S;
    }

    int Time::setHours(int Hnum){ //set hours
        Hours = Hnum;
        return Hours;
    }

    int Time::setMinutes(int Mnum){ //set minutes, converts to hours if M>59
        if(Mnum > 59){
            Hours += Mnum/60;
            Mnum -= 60*(Mnum/60);
            Minutes = Mnum;
        }
        else{
            Minutes = Mnum;
        }
        return Minutes;
    }

    int Time::setSeconds(int Snum){ //set seconds,converts to hrs and mns if S>59
        if(Snum > 59){
            Minutes += Snum/60;
            setMinutes(Minutes);
            Snum -= 60*(Snum/60);
            Seconds = Snum;
        }
        else{
            Seconds = Snum;
        }
        return Seconds;
    }

    int Time::getHours(){ //return hours
        return Hours;
    }

    int Time::getMinutes(){ //return minutes
        return Minutes;
    }

    int Time::getSeconds(){ //return seconds
        return Seconds;
    }

    string Time::convToStr(){ //return string with time
        string timeStr=to_string(Hours)+":"+to_string(Minutes)+":"+to_string(Seconds);
        return timeStr;
    }

    void Time::addTime(int Hours,int Minutes, int Seconds){// adds time
        setHours(getHours()+Hours);
        setMinutes(getMinutes()+Minutes);
        setSeconds(getSeconds()+Seconds);
    } //potentially, use time0.addTime(time1.getSeconds) to add or subtract

    int Time::convToSecs(){ // converts H and M to S.
        int buf = Hours*60*60+Minutes*60;
        return buf;
    }

    float Time::convToMins(){ // converts H and S to M, FP result.
        float buf = Hours*60+Minutes+Seconds/60;
        return buf;
    }

    float Time::convToHous(){ // converts M and S to H. FP result.
        float buf = Minutes/60+Seconds/3600+Hours;
        return buf;
    }

