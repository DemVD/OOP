#include <iostream>
#include <string.h>
#include "date_class.h"
#include "exceptions.h"

using namespace std;


Date::Date(unsigned const day, unsigned const month, unsigned const year){
    _day = day;
    _month = month;
    _year = year;
}

void Date::setDate(unsigned const day, unsigned const month, unsigned const year){
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::setDay(unsigned const day){
    if(day <= 28) // к любому месяцу можно добавить 28 дней
    {
        _day = day;
    }
    else // если дней больше - нужно смотреть месяцы и года..
    {
        if(day == 29) // к люб. мес. (кроме февраля в весок. год) можно + 29 д
        {
            if(_month == 2 && (_year%4==0) && (_year%100!=0)) // если февраль И весок. год
            {
                _day = day;
            }
            else if(_month != 2) // если месяц != февраль => к любому месяцу можно + 29 д
            {
                _day = day;
            }
            else // это февраль, дней 29 а год не весокосный..
            {
                setMonth(_month+1); // это будет след. месяц
                setDay(day-28); // и первое число
            }
        }
        else if(day == 30 || day == 31) // 30 или 31 день
        {
            if(day==30 && _month != 2) // 30 дней и не февраль
            {
                _day=day;
            }
            else if(day==30 && _month==2 &&(_year%4==0)&&(_year%100!=0)) // 30 дней и февраль и весок. год
            {
                setMonth(_month+1); // это будет след. месяц
                setDay(day-29); // и 1 число след. месяца
            }
            else if(day==30 && _month==2) // 30 дней и февраль но не весокосный год
            {
                setMonth(_month+1); // это будет след. месяц
                setDay(day-28); // и 2 число след. месяца
            }
            else if(day==31 && _month != 2) // 31 день не февраль
            {
                if(_month!=4&&_month!=6&&_month!=9&&_month!=11) // если месяц не апр,июн,сен,ноя
                {
                    _day = day;
                }
                else{ // это апр/июн/сен/ноя
                    setMonth(_month+1); // это будет след. месяц
                    setDay(day-31); // и какоето число след. месяца
                }
            }
            else if(day==31 && _month == 2){ // 31 день и февраль
                if((_year%4==0)&&(_year%100!=0)) // феврал и весок.
                {
                    setMonth(_month+1); // это будет след. месяц
                    setDay(day-29); // и какоето число след. месяца
                }
                else // 31 день февраль и не весок. год
                {
                    setMonth(_month+1); // это будет след. месяц
                    setDay(day-28); // и какоето число след. месяца
                }
            }
        }
        else{ // дней больше 31 дня => вычесть 31 => рекурсия
            if(_month == 2) // если февраль
            {
                if((_year%4==0)&&(_year%100!=0)) // февраль и весокосный
                {
                    setMonth(_month+1); // это будет след. месяц
                    setDay(day-29); // и какоето число след. месяца
                }
                else // февраль и не весокосный
                {
                    setMonth(_month+1); // это будет след. месяц
                    setDay(day-28); // и какоето число след. месяца
                }
            }
            else if(_month!=4&&_month!=6&&_month!=9&&_month!=11) // если месяц не апр,июн,сен,ноя
            {
                setMonth(_month+1); // это будет след. месяц
                setDay(day-31); // и какоето число след. месяца
            }
            else // месяц - апр/июн/сен/ноя
            {
                setMonth(_month+1); // это будет след. месяц
                setDay(day-30); // и какоето число след. месяца
            }
        }
    }
}

void Date::setMonth(unsigned const month){
    if(month < 13){//в году нет >12 месяцев
        _month = month;
    }
    else{
        unsigned y = month/12;
        setYear(y);
        _month = month-(12*y);
    }
}

void Date::setYear(unsigned const  year){
    _year += year;
}

unsigned Date::day() const{
    return _day;
}

unsigned Date::month() const{
    return _month;
}

unsigned Date::year() const{
    return _year;
}

string Date::strDate() const{
    string strBuf = to_string(_day)+"."+to_string(_month)+"."+to_string(_year);
    return strBuf;
}

unsigned Date::convToDays() const{
    unsigned d=0;
    for(unsigned y=0;y<_year;y++){
        if((y%4==0)&&(y%100!=0)){ // в весок. году 366 дней
            d+=366;
        }
        else{ // в обычном году 365 дней.
            d+=365;
        }
    }
    for(unsigned m=1;m<_month+1;m++){
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            d+=31;
        }
        else if(m==2){
            if((_year%4==0)&&(_year%100!=0)){
                d+=29;
            }
            else{
                d+=28;
            }
        }
        else{
            d+=30;
        }
    }
    return d;
}

unsigned Date::convToMonths() const{
    unsigned m=0;
    m+=_year*12;
    m+=_month;
    if(_day > 15){m++;}
    return m;
}

unsigned Date::convToYears() const{
    unsigned y = _year;
    if(_month > 5){y++;}
    return y;
}

Date Date::operator + (const Date D){
    Date Dres;
    Dres.setYear(_year+D._year);
    Dres.setMonth(_month+D._month);
    Dres.setDay(_day+D._day);
    return Dres;
}

Date Date::operator - (const Date D){
    unsigned selfDays = convToDays();
    unsigned negativeDays = D.convToDays();
    if(selfDays < negativeDays){
        throw(negativeYears);
    }
    unsigned finalDays = selfDays - negativeDays;
    Date Dres;
    Dres.setDay(finalDays);
    return Dres;
}

