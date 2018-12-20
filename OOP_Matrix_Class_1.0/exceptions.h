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


const static Exception indexError(1,"\nError: index is out of range.\n");
const static Exception matrSumSizeError(2,"\nError: summed matrixes MUST be of same size.\n");
const static Exception matrUndecl(3,"\nError: matrix has no elements.\n");
const static Exception multipMsizeErr(4,"\nError: MxN <=> col n in M == line n in N!\n");
const static Exception diagMsizeErr(5,"\nError: diagonal matrix MUST have the same num of rows and cols.\n");
const static Exception undefinedMGetDet(6,"\nError: can't calculate determinant from an undefined matrix.\n");
const static Exception nonSameSizeMGetDet(7,"\nError: you can only get the determinant from a matrix of the same size!\n");
const static Exception nonSameSizeMGetInversed(8,"\nError: you can only get inversed matrix from a matrix of the same size!\n");
const static Exception inversedMwithZERODet(9,"\nError: you cant get inversed matrix when it's Det == 0!\n");

#endif // EXCEPTIONS_H
