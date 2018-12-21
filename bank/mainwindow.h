#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "summa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void on_spinBox_1_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(double arg1);

private:
    calcIncome inc;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
