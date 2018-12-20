#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H


class GeometricFigure{
private:
    float A=0; // одна из сторон фигуры
    float B=0; // другая из сторон фигуры
public:
    void setA(float a); // установить одну из сторон
    float getA(); // получить одну из сторон
    void setB(float b); // установить другую из сторон
    float getB(); // получить другую из сторон
    float perimCalc(); // вычисление периметра
    float areaCalc(); // вычисление площади
};


class Rectangle :public GeometricFigure{
};


class Triangle :public GeometricFigure{
private:
    float C=0; // еще одна сторона С
public:
    void setC(float c); // установить сторону С
    float getC(); // получить сторону С
    float calcHa(); // вычислить высоту на стороне а
    float perim(); // вычисление периметра ПЕРЕОПРЕДЕЛЕНИЕ
    float area(); // вычисление площади ПЕРЕОПРЕДЕЛЕНИЕ
};


class Circle :public GeometricFigure{ // стоит ли использовать А как радиус, или
public: // сделать новое поле для подкласса? Тогда ничего не наследуется!
    float perim(); // вычислить периметр ПЕРЕОПРЕДЕЛЕНИЕ
    float area(); // вычислить площадь ПЕРЕОПРЕДЕЛЕНИЕ
};

#endif // GEOMETRICFIGURE_H
