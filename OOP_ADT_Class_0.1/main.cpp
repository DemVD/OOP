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
    cout<<time1.getHours()<<endl<<time1.getMinutes()<<endl<<time1.getSeconds()<<endl;

    vector<int> timeVect = time1.getTime();
    for(unsigned i=0;i<3;i++){
        cout << timeVect[i] << endl;
    }
}
