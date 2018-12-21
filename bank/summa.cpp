#include "summa.h"


void calcIncome::set_rubs(double r){
    _rubs = r;
}

double calcIncome::rubs(){
    return _rubs;
}

void calcIncome::set_years(float y){
    _years = y;
}

float calcIncome::years(){
    return _years;
}

void calcIncome::set_percentage(float p){
    _percentage = p;
}

float calcIncome::percentage(){
    return _percentage;
}

double calcIncome::Income(){
    return _rubs + (_rubs * _percentage / 100) * _years;
}
