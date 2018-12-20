#include <vector>
#include <iostream>
#include <time.h>
#include "matrclass.h"
#include "exceptions.h"

using namespace std;


void Matrix::getMatrixMinor(float **mas, float **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
      if (ki == i) di = 1;
      dj = 0;
      for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
        if (kj == j) dj = 1;
        p[ki][kj] = mas[ki + di][kj + dj];
      }
    }
  }

float Matrix::getMatrixDeterminant(float **mas, int m) {
  int i, j, k, n;
  float d;
  float **p;
  p = new float*[m];
  for (i = 0; i<m; i++)
    p[i] = new float[m];
  j = 0; d = 0;
  k = 1; //(-1) в степени i
  n = m - 1;
  if (m<1) throw(undefinedMGetDet);
  if (m == 1) {
    d = mas[0][0];
    return(d);
  }
  if (m == 2) {
    d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
    return(d);
  }
  if (m>2) {
    for (i = 0; i<m; i++) {
      getMatrixMinor(mas, p, i, 0, m);
      d = d + k * mas[i][0] * getMatrixDeterminant(p, n);
      k = -k;
    }
  }
  return(d);
}

Matrix::Matrix(){ // конструктор по умолчанию
    vector<float> line(1);
    matrix.push_back(line);
}

Matrix::Matrix(const unsigned m,const unsigned n){ // конструктор с параметрами
    for(unsigned i=0;i<m;i++){
        vector<float> line(n);
        matrix.push_back(line);
    }
}

void Matrix::MFillRand(const float leftLim,const float rightLim){ // рандомное заполнение матрицы
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            matrix[i][j] = (1.0*rand())/RAND_MAX*(rightLim-leftLim)+leftLim;
        }
    }
}

void Matrix::MShow(string str){ // вывод матрицы
    cout<<endl<<str<<endl;
    for(auto vect:matrix){
        for(auto elem:vect){
            cout<<"   "<<elem;
        }
        cout<<endl;
    }
    cout<<endl;
}

void Matrix::MFillConstV(const float Val){ // заполнение матрицы одним числом
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            matrix[i][j] = Val;
        }
    }
}

vector<float> Matrix::MGetLine(const unsigned lineNum){ // получение указанной строки
    if(lineNum >= matrix.size()){
        throw(indexError);
    }
    vector<float> buf;
    for(auto elem:matrix[lineNum]){
        buf.push_back(elem);
    }
    return buf;
}

void Matrix::MSetDiagMat(){ // обращение матрицы в диагональную
    if(matrix.size() != matrix[0].size()) throw(diagMsizeErr);
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            matrix[i][j] = 0;
        }
        matrix[i][i] = 1;
    }
}

float Matrix::MGetElem(const unsigned i,const unsigned j){ // доступ к элементу
    if(i>=matrix.size() || j >= matrix[0].size()){
        throw(indexError);
    }
    return matrix[i][j];
}

Matrix Matrix::operator + (const Matrix &m){ // сложение двух матриц
    if(matrix.size() != m.matrix.size() || matrix[0].size() != m.matrix[0].size()){
        throw(matrSumSizeError);
    }
    Matrix M;
    M.matrix = m.matrix;
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            M.matrix[i][j] = matrix[i][j]+m.matrix[i][j];
        }
    }
    return M;
}

void Matrix::operator += (const Matrix &m){
    if(matrix.size() != m.matrix.size() || matrix[0].size() != m.matrix[0].size()){
        throw(matrSumSizeError);
    }
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            matrix[i][j] = matrix[i][j]+m.matrix[i][j];
        }
    }
}

Matrix Matrix::operator - (Matrix &m){ // вычитание двух матриц
    Matrix M = m * (-1);
    M =  operator + (M);
    return M;
}

void Matrix::operator -= (Matrix &m){
    Matrix M = m * (-1);
    M =  operator + (M);
    matrix = M.matrix;
    //matrix =  operator += (M).matrix;
    // or self =  Matrix new_mat; присвоить к Матрице Матрицу.
}

Matrix Matrix::operator * (const Matrix &m){ // перемножение двух матриц
    if(matrix[0].size() != m.matrix.size()) throw(multipMsizeErr);
    Matrix M(matrix.size(),m.matrix[0].size());
      for (unsigned i=0;i<matrix.size();i++){
        for (unsigned j=0;j<m.matrix[0].size();j++){
            M.matrix[i][j] = 0;
            for (unsigned k=0;k<matrix[0].size();k++){
                M.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
      }
      return M;
}

void Matrix::operator *=(const Matrix &m){
    if(matrix[0].size() != m.matrix.size()) throw(multipMsizeErr);
    Matrix M(matrix.size(),m.matrix[0].size());
      for (unsigned i=0;i<matrix.size();i++){
        for (unsigned j=0;j<m.matrix[0].size();j++){
            M.matrix[i][j] = 0;
            for (unsigned k=0;k<matrix[0].size();k++){
                M.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
      }
      matrix = M.matrix;
}

Matrix Matrix::operator * (const float n){ // умножение матрицы на число|не реализ. чис*мат
    Matrix M;
    M.matrix = matrix;
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            M.matrix[i][j] *= n;
        }
    }
    return M;
}

void Matrix::operator *= (const float n){
    for(unsigned i=0;i<matrix.size();i++){
        for(unsigned j=0;j<matrix[0].size();j++){
            matrix[i][j] *= n;
        }
    }
}

void Matrix::MTranspos(){ // транспонирование матрицы
    vector<vector<float>> mT;
    vector<float> mTline;
    for(unsigned i=0;i<matrix[0].size();i++){
        for(unsigned j=0;j<matrix.size();j++){
            mTline.push_back(matrix[j][i]);
        }
        mT.push_back(mTline);
        mTline.clear();
    }
    matrix.clear();
    matrix = mT;
}

float Matrix::MDeterm(){
    if(matrix.size() != matrix[0].size()) throw(nonSameSizeMGetDet);
    unsigned m = matrix.size();
    float **M;
    M = new float*[m];
    for (unsigned i=0;i<m;i++){
        M[i] = new float[m];
    }
    for(unsigned i=0;i<m;i++){
        for(unsigned j=0;j<m;j++){
            M[i][j] = matrix[i][j];
        }
    }
    float det = getMatrixDeterminant(M, m);
    return det;
}

Matrix Matrix::getMInversed(){ // обратная матрица
    if (matrix.size() != matrix[0].size()) throw(nonSameSizeMGetInversed);
    if (MDeterm() == 0) throw(inversedMwithZERODet);
    Matrix MT; // buffer matrix
    MT.matrix = matrix;
    MT.MTranspos(); // transposed original matrix
    float oneDivDet = (1/MDeterm());
    MT = MT * oneDivDet; // MT now is the result.
    return MT;
}
