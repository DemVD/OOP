#ifndef SUMMA_H
#define SUMMA_H



class calcIncome{
private:
    double _rubs=0;
    float _years=1;
    float _percentage=0;
public:
    void set_rubs(double r);
    double rubs();
    void set_years(float y);
    float years();
    void set_percentage(float p);
    float percentage();
    double Income();
};

#endif // SUMMA_H
