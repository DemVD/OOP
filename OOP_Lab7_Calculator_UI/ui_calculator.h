#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H
#include <QMainWindow>
#include <string.h>
#include "class_calculator.h"

namespace Ui {
class ui_Calculator;
}

class ui_Calculator : public QMainWindow
{
    Q_OBJECT

public:
    void nulifyBufStr(); // занулить буфер строку
    void AddToBufStr(const string n); // добавить к буферу строке
    void nulifyBufDouble(); // занулить буфер число
    void AddToBufDouble(const double n); // добавить к буфер числу
    string bufStr(); // получить буфер строка (для вывода на экран)
    double bufDouble(); // получить буфер число (для записи в класс)
    void textShowTB1() const;
    void textShowTB2() const;
    void onNumButtonClick(const int n); // при каждом нажатии вызов
    void onDotButtonClick(); // при нажатии на точку
    void onActionButtonClick(const string act); // при нажатии на кнопку действия с N1,N2
    void onActionButtonClick2(const string act); // при нажатии на действие только с N1
    void prepForEqu();
    void prepForEqu2();

    explicit ui_Calculator(QWidget *parent = nullptr);
    ~ui_Calculator();
private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    void on_pushButton_DOT_clicked();
    void on_pushButton_ADD_clicked();
    void on_pushButton_SUB_clicked();
    void on_pushButton_MUL_clicked();
    void on_pushButton_DIV_clicked();

    void on_pushButton_SIN_clicked();
    void on_pushButton_COS_clicked();
    void on_pushButton_TAN_clicked();
    void on_pushButton_LGE_clicked();
    void on_pushButton_EXP_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_EQU_clicked();

    void on_pushButton_POW_clicked();

private:
    string _bufStr=""; // буфер строка (вывод на экран)
    string _historyStr=""; // строка истории вычислений
    string _act=""; // действие (для знака '=')
    double _bufDouble = 0; // буфер число (ввод в класс)
    bool _actionRunningDOT = 0; // флажок точки (коректное пользование)
    bool _actionRunningOPERAND1 = 0; // флажок операций 1 (корректное пользование)
    Calculator N1;

    Ui::ui_Calculator *ui;
};

#endif // UI_CALCULATOR_H
