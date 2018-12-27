#ifndef DATE_CLASS_H
#define DATE_CLASS_H
#include <iostream>
#include <string.h>

using namespace std;


class Date{
private:
    unsigned _day=0;
    unsigned _month=0;
    unsigned _year=0;
public:
    Date(unsigned const day=1, unsigned const month=1, unsigned const year=1);
    void setDate(unsigned const day, unsigned const month, unsigned const year);
    void setDay(unsigned const day);
    void setMonth(unsigned const month);
    void setYear(unsigned const  year);
    unsigned day() const;
    unsigned month() const;
    unsigned year() const;
    string strDate() const;
    unsigned convToDays() const;
    unsigned convToMonths() const;
    unsigned convToYears() const;
    Date operator + (const Date D);
    Date operator - (const Date D);
};

#endif // DATE_CLASS_H
