#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <vector>

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


const static Exception negativeYears(1,"\nError: resulting years are B.C while the program only works with A.C. years!\n");


#endif // EXCEPTIONS_H
