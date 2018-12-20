#ifndef MATRCLASS_H
#define MATRCLASS_H
#include <vector>
#include <iostream>

using namespace std;


class Matrix{
private:
    vector<vector<float>> matrix;
protected:
    void getMatrixMinor(float **mas, float **p, int i, int j, int m); // получение минора
    float getMatrixDeterminant(float **mas, int m); // отдельная рекурсивная функция вычисления определителя
public:
    Matrix(); // конструктор по умолчанию
    Matrix(const unsigned m, const unsigned n); // конструктор с параметрами
    void MFillRand(const float leftLim = -100, const float rightLim = 100); // рандомное заполнение матрицы
    void MShow(string str = ""); // вывод матрицы
    void MFillConstV(const float Val = 0); // заполнение матрицы одним числом
    vector<float> MGetLine(const unsigned lineNum = 0); // получение указанной строки
    void MSetDiagMat(); // превращение матрицы в диагональную
    float MGetElem(const unsigned i=0, const unsigned j=0); // доступ к элементу
    Matrix operator + (const Matrix &m); // опер-р сложения матриц
    void operator += (const Matrix &m);
    Matrix operator - (Matrix &m); // опер-р вычитания матриц
    void operator -= (Matrix &m);
    Matrix operator * (const Matrix &m); // опер-р перемножения матриц
    void operator *= (const Matrix &m);
    Matrix operator * (const float n); // опер-р перемножения МАТРИЦЫ и ЧИСЛА
    void operator *= (const float n);
    void MTranspos(); // транспонирование матрицы
    float MDeterm(); // определитель матрицы
    Matrix getMInversed(); // обратная матрица
};


#endif // MATRCLASS_H
