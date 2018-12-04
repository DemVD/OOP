#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "header.h"
#include "timeclass.h"


using namespace std;

int main(){
    Time time1;
    time1.setHours(5);
    time1.setMinutes(30);
    time1.setSeconds(3601);
    time1.showTime();

    time1.addTime(30,60,90);
    time1.showTime();
    Time time2;
    time2.addTime(1,1,1);
    time1.addTime(time2.getSeconds(),time2.getMinutes(),time2.getHours());
    time1.showTime();
    cout<<"Converting to seconds"<<endl;
    time1.convToSecs();
    time1.showTime();
    cout<<"Converting to minutes"<<endl;
    time1.convToMins();
    time1.showTime();
    cout<<"Converting to seconds AGAIN"<<endl;
    time1.convToSecs();
    time1.showTime();
    cout<<"Converting to Hours"<<endl;
    time1.convToHous();
    time1.showTime();
    cout<<"Converting to seconds AGAIN x2"<<endl;
    time1.convToSecs();
    time1.showTime();
    cout<<"Back to normal time"<<endl;
    time1.setSeconds(time1.getSeconds());
    time1.showTime();
}
