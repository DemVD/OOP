#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

using namespace std;

class exceptionType{
public:
    int exceptionID;
    string exceptionInfo;

    exceptionType(int i, string s)
    {
        exceptionID = i;
        exceptionInfo = s;
    }
};

namespace exceptions{

}

#endif // EXCEPTIONS_H
