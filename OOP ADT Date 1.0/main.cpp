#include <QCoreApplication>
#include "date_class.h"
#include "exceptions.h"

using namespace std;


int main(){
    Date d;
    d.setDate(28,2,2020);
    cout<<"Date: "<<d.strDate()<<endl;
    d.setDay(29);
    cout<<"Date: "<<d.strDate()<<endl;

    Date d2;
    d2.setDate(0,0,2000);
    cout<<"modified d2: "<<d2.strDate()<<endl;
    d2.setDay(150); // 150 - 31(jan) - 29(feb,Vesokos) - 31(mar) - 30(apr) = 29.04.2000
    cout<<"modified d2: "<<d2.strDate()<<endl;
}
