#include <math.h>
#include <vector>
#include "header.h"

using namespace std;



class Time{
public:
    int setHours(Hnum){
        Hours = Hnum;
        return Hours;
    }

    int setMinutes(Mnum){
        Minutes = Mnum;
        return Minutes;
    }

    int setSeconds(Snum){
        Seconds = Snum;
        return Seconds;
    }

    int getTime(spec){
        switch(spec){
            case "Hours": return Hours;
            case "Minutes": return Minutes;
            case "Seconds": return Seconds;
        }

    }

private:
    int Hours;
    int Minutes;
    int Seconds;
};
