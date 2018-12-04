#ifndef TIMECLASS_H
#define TIMECLASS_H
#include <math.h>
#include <vector>
#include <iostream>
#include "header.h"

using namespace std;


class Time{
private:
    float Hours=0;
    float Minutes=0;
    float Seconds=0;
public:
    float setHours(int Hnum){
        Hours = Hnum;
        cout<<"Set Hours to "<<Hnum<<endl;
        return Hours;
    }

    float setMinutes(int Mnum){
        if(Mnum > 59){
            cout<<"Adding "<<Mnum<<" Minutes..."<<endl;
            Hours += Mnum/60;
            cout<<"Set Hours to "<<Mnum/60<<endl;
            Mnum -= 60*(Mnum/60);
            Minutes = Mnum;
            cout<<"Set Minutes to "<<Mnum<<endl;
        }
        else{
            Minutes = Mnum;
            cout<<"Set Minutes to "<<Mnum<<endl;
        }
        return Minutes;
    }

    float setSeconds(int Snum){
        if(Snum > 59){
            cout<<"Adding "<<Snum<<" Seconds..."<<endl;
            Minutes += Snum/60;
            setMinutes(Minutes);
            Snum -= 60*(Snum/60);
            Seconds = Snum;
            cout<<"Set Seconds to "<<Snum<<endl;
        }
        else{
            Seconds = Snum;
            cout<<"Set Seconds to "<<Snum<<endl;
        }
        return Seconds;
    }

    float getHours(){
        return Hours;
    }

    float getMinutes(){
        return Minutes;
    }

    float getSeconds(){
        return Seconds;
    }

    string convToStr(){
        string timeStr="Time: "+to_string(Hours)+" "+to_string(Minutes)+" "+to_string(Seconds);
        return timeStr;
    }

    void showTime(){
        cout<<"Current time: "<<getHours()<<" "<<getMinutes()<<" "<<getSeconds()<<endl;
    }

    void addTime(int Seconds=0,int Minutes=0, int Hours=0){
        cout<<"Adding time: "<<Hours<<" "<<Minutes<<" "<<Seconds<<endl;
        setHours(getHours()+Hours);
        setMinutes(getMinutes()+Minutes);
        setSeconds(getSeconds()+Seconds);
    }

    float convToSecs(){
        Minutes += Hours*60;
        Hours=0;
        Seconds += Minutes*60;
        Minutes=0;
        return Seconds;
    }

    float convToMins(){
        convToSecs();
        Minutes += Seconds/60;
        Seconds=0;
        return Minutes;
    }

    float convToHous(){
        convToSecs();
        Hours += Seconds/3600;
        Seconds=0;
        return Hours;
    }
};


#endif // TIMECLASS_H
