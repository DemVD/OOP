#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


class Exception{
public:
    int excepID;
    string excepDescr;

    Exception(int i, string s)
    {
        excepID = i;
        excepDescr = s;
    }
};


const static Exception disivionByZero(1,"\nError: Division by zero!");

#endif // EXCEPTIONS_H
