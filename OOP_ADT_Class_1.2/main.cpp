#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "header.h"
#include "timeclass.h"


using namespace std;

int main(){
    Time time1(23,59,5);
    Time time2(0,0,59);
    Time time3;
    time3.addTime(time1.getSeconds(),time1.getMinutes(),time1.getHours());
    time3.addTime(time2.getSeconds(),time2.getMinutes(),time2.getHours());
    cout<<"Time3: "<<time3.convToStr()<<endl;
    Time time4;
    time4.setSeconds(4000);
    cout<<"Time4: "<<time4.convToStr()<<endl;
}
