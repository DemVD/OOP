#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->sum->setText(QString::number(inc.Income()));
}

void MainWindow::on_spinBox_1_valueChanged(int arg1)
{
    inc.set_rubs(arg1); // ui->spinBox_1->value()
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    inc.set_years(arg1); // ui->spinBox_2->value()
}

void MainWindow::on_spinBox_3_valueChanged(double arg1)
{
    inc.set_percentage(arg1); // ui->spinBox_3->value()
}
