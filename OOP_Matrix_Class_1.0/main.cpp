#include <QCoreApplication>
#include <vector>
#include "matrclass.h"
#include "exceptions.h"

using namespace std;


int main()
{
    srand(time(nullptr)); // where to put??
    Matrix m1(4,4);
    m1.MShow("generated m1");
    m1.MFillConstV(5);
    m1.MShow("filled m1 with const val = 5");
    Matrix m2(4,4);
    m2.MFillConstV(2);
    m2.MShow("new matrix m2 with const val = 2");

    Matrix m3 = m1 + m2;
    m3.MShow("m1 + m2 =");
    Matrix m4 = m1 - m2;
    m4.MShow("m1 - m2 =");
    Matrix m5 = m1 * m2;
    m5.MShow("m1 * m2 =");

    Matrix mt1(1,4);
    mt1.MFillConstV(8);
    Matrix mt2(4,1);
    mt2.MFillConstV(2);
    mt1.MShow("mt1 - matrix-line");
    mt2.MShow("mt2 - matrix-column");
    Matrix mt3 = mt1 * mt2;
    mt3.MShow("mt1 * mt2 =");

    Matrix m6 = m1 * 5;
    m6.MShow("m1 * 5 =");
    //Matrix m7 = 5 * m1;

    Matrix m7(4,4);
    m7.MSetDiagMat();
    m7.MShow("diagonal matrix");

    Matrix m8(4,2);
    m8.MFillRand();
    m8.MShow("new matrix:");
    m8.MTranspos();
    m8.MShow("Transposed new matrix:");

    Matrix m9(2,2);
    m9.MFillConstV(5);
    m9.MShow();
    cout<<"\nm9's determinant:"<<m9.MDeterm()<<endl;
    try {
        Matrix m10 = m9.getMInversed();
        m10.MShow("Inversed matrix m9^-1:");
    } catch (Exception EXC) {
        if (EXC.excepID == 9) cout<<EXC.excepDescr;
    }
    m9.MFillRand(1,5);
    m9.MShow("newly generated m9:");
    cout<<"\nm9's new det: "<<m9.MDeterm()<<endl;
    Matrix m11 = m9.getMInversed();
    m11.MShow("inversed m9^-1 matrix:");

    m1.MShow("m1 once again");
    m1 *= 2;
    m1.MShow("operator *= on m1 and constant NUM:");

    m2.MShow("m2 again");
    m1.MFillConstV(5);
    m1.MShow("m1 filled with constV");
    m1 *= m2;
    m1.MShow("operator *= on m1 and m2:");
}
