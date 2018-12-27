#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H


class GeometricFigure{
protected:
    float _A=0, _B=0; // две стороны фигуры
public:
    GeometricFigure(); // конструктор по умолчанию
    GeometricFigure(const float A, const float B); // конструктор с параметрами
    void setA(const float A); // установить одну из сторон
    float A() const; // получить одну из сторон
    void setB(const float B); // установить другую из сторон
    float B() const; // получить другую из сторон
    float virtual perim() const; // вычисление периметра
    float virtual area() const; // вычисление площади
};


class Rectangle :public GeometricFigure{ // полное наследование
public: // не смотря на полное наследование требуются конструкторы
    Rectangle();
    Rectangle(const float A, const float B);
    // именно ^ для  Rectangle *r1 = new Rectangle(5,5); в main
};


class Triangle :public GeometricFigure{ // наследование + добавление
private:
    float _C=0; // еще одна сторона С
public:
    Triangle(); // конструктор по умолчанию (как сделать :GeometricFigure(){} ?)
    Triangle(const float A, const float B, const float C); // конструктор с параметрами
    void setC(const float c); // установить сторону С
    float C() const; // получить сторону С
    float calcHa() const; // вычислить высоту на стороне а
    float perim() const; // вычисление периметра ПЕРЕОПРЕДЕЛЕНИЕ
    float area() const; // вычисление площади ПЕРЕОПРЕДЕЛЕНИЕ
};


class Circle :public GeometricFigure{ // ничего не наследуется?
private:
    float _R=0; // радиус круга
public:
    Circle(); // конструктор по умолчанию
    Circle(const float R); // конструктор с параметрами
    void setR(const float R); // установить радиус
    float R() const; // получить радиус
    float perim() const; // вычислить периметр (ДИАМЕТР) переопр
    float area() const; // вычислить площадь ПЕРЕОПРЕДЕЛЕНИЕ
};

#endif // GEOMETRICFIGURE_H
