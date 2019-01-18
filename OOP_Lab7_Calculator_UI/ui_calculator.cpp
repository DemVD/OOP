#include <string.h>
#include <qstring.h>
#include <math.h>
#include "ui_calculator.h"
#include "ui_ui_calculator.h"

ui_Calculator::ui_Calculator(QWidget *parent) : // виджет
    QMainWindow(parent),
    ui(new Ui::ui_Calculator)
{
    ui->setupUi(this);
}

ui_Calculator::~ui_Calculator() // деструктор
{
    delete ui;
}

void ui_Calculator::nulifyBufStr(){ // занулить буфер строку
    _bufStr = "";
}

void ui_Calculator::AddToBufStr(const string n){ // добавить в буфер строку
    _bufStr += n;
}

void ui_Calculator::nulifyBufDouble(){ // занулить буфер число
    _bufDouble = 0;
}

void ui_Calculator::AddToBufDouble(double n){ // добавить в буфер число
    _bufDouble += n;
}

string ui_Calculator::bufStr(){ // вернуть буфер строку
    return _bufStr;
}

double ui_Calculator::bufDouble(){ // вернуть буфер число
    return _bufDouble;
}

void ui_Calculator::textShowTB1() const{
    QString str = QString::fromStdString(_bufStr);
    ui->textBrowser->setText(str);
}

void ui_Calculator::textShowTB2() const{
    QString str = QString::fromStdString(_historyStr);
    ui->textBrowser_2->setText(str);
}

void ui_Calculator::onNumButtonClick(const int n){
    _bufStr += to_string(n);
    _bufDouble += n;
    textShowTB1();
}

void ui_Calculator::onDotButtonClick(){
    if(_bufStr.length() == 0 && _actionRunningDOT == 0){
        _bufStr = "0.";
        _actionRunningDOT = 1;
        textShowTB1();
    }
    else if(_actionRunningDOT == 0){
        _bufStr += ".";
        _actionRunningDOT = 1;
        textShowTB1();
    }
}

void ui_Calculator::onActionButtonClick(const string act){
    if(_bufStr.length() != 0 && _actionRunningOPERAND1 == 0){
        _bufDouble = stod(_bufStr);
        N1.setN1(_bufDouble);
        _historyStr+=_bufStr+"\n";
        _bufStr = act;
        textShowTB1();
        textShowTB2();
        _actionRunningOPERAND1 = 1;
        _actionRunningDOT=0;
        _act = act;
    }
    else if(_actionRunningOPERAND1==1 && _act!=act && _bufStr!="^" && _bufStr.length()==1){
        _bufStr = act;
        textShowTB1();
        _act = act;
    }
}

void ui_Calculator::onActionButtonClick2(const string act){
    if(_bufStr.length() == 0){
        _act = act;
        _bufStr = act+"(";
        textShowTB1();
    }
}

void ui_Calculator::on_pushButton_0_clicked(){
    onNumButtonClick(0);
}

void ui_Calculator::on_pushButton_1_clicked(){
    onNumButtonClick(1);
}

void ui_Calculator::on_pushButton_2_clicked(){
    onNumButtonClick(2);
}

void ui_Calculator::on_pushButton_3_clicked(){
    onNumButtonClick(3);
}

void ui_Calculator::on_pushButton_4_clicked(){
    onNumButtonClick(4);
}

void ui_Calculator::on_pushButton_5_clicked(){
    onNumButtonClick(5);
}

void ui_Calculator::on_pushButton_6_clicked(){
    onNumButtonClick(6);
}

void ui_Calculator::on_pushButton_7_clicked(){
    onNumButtonClick(7);
}

void ui_Calculator::on_pushButton_8_clicked(){
    onNumButtonClick(8);
}

void ui_Calculator::on_pushButton_9_clicked(){
    onNumButtonClick(9);
}

void ui_Calculator::on_pushButton_DOT_clicked(){
    onDotButtonClick();
}

void ui_Calculator::on_pushButton_ADD_clicked(){
    onActionButtonClick("+");
}

void ui_Calculator::on_pushButton_SUB_clicked(){
    if(_bufStr.length() > 0){
        onActionButtonClick("-");
    }
    else{
        _bufStr="-";
    }
    if(_act == "^"){
        _bufStr+="-";
    }
}

void ui_Calculator::on_pushButton_MUL_clicked(){
    onActionButtonClick("*");
}

void ui_Calculator::on_pushButton_DIV_clicked(){
    onActionButtonClick("%");
}

void ui_Calculator::on_pushButton_SIN_clicked(){
    onActionButtonClick2("SIN");
}

void ui_Calculator::on_pushButton_COS_clicked(){
    onActionButtonClick2("COS");
}

void ui_Calculator::on_pushButton_TAN_clicked(){
    onActionButtonClick2("TAN");
}

void ui_Calculator::on_pushButton_LGE_clicked(){
    onActionButtonClick2("LGE");
}

void ui_Calculator::on_pushButton_EXP_clicked(){
    onActionButtonClick2("EXP");
}

void ui_Calculator::on_pushButton_C_clicked(){
    _actionRunningDOT=0;
    _actionRunningOPERAND1=0;
    _bufDouble=0;
    _bufStr="";
    _historyStr="";
    textShowTB1();
    textShowTB2();
}

void ui_Calculator::on_pushButton_EQU_clicked(){
    if(_act == "+"){
        prepForEqu();
        N1.ADD();
    }
    else if(_act == "-"){
        prepForEqu();
        N1.SUB();
    }
    else if(_act == "*"){
        prepForEqu();
        N1.MUL();
    }
    else if(_act == "%"){
        prepForEqu();
        //if(N1.N2() == 0){throw(1);}
        N1.DIV();
    }
    else if(_act == "^"){
        prepForEqu();
        N1.POW();
    }
    else if(_act == "SIN"){
        prepForEqu2();
        N1.SIN();
    }
    else if(_act == "COS"){
        prepForEqu2();
        N1.COS();
    }
    else if(_act == "TAN"){
        prepForEqu2();
        N1.TAN();
    }
    else if(_act == "LGE"){
        prepForEqu2();
        N1.LGE();
    }
    else if(_act == "EXP"){
        prepForEqu2();
        N1.EXP();
    }

    _historyStr += _bufStr+"\n";
    _bufStr = to_string(N1.R());
    textShowTB1();
    textShowTB2();
    _historyStr += _bufStr+"\n";
    _bufStr="";
    _actionRunningDOT=0;
    _actionRunningOPERAND1=0;
}

void ui_Calculator::prepForEqu(){
    _bufStr.erase(0,1);
    N1.setN2(stod(_bufStr));
    _bufStr = _act+"\n"+_bufStr+"\n=";
}

void ui_Calculator::prepForEqu2(){
    _bufStr.erase(0,4);
    N1.setN1(stod(_bufStr));
    _bufStr = _act+"\n"+_bufStr+"\n=";
}

void ui_Calculator::on_pushButton_POW_clicked(){
    onActionButtonClick("^");
}
