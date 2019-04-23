#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
//#include <qshortcut.h>
#include "chatbot.h"

using namespace ChatBot_NS;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ChatBot CB;

private slots:
    void on_pushButton_sendMsg_clicked();
    //void slotShortCutCtrlEnter(); // слот для обработки нажатий горячих клавиш.

private:
    Ui::MainWindow *ui;
    //QShortcut *keyCtrlEnter; // объект горячей клавиши CTRL + ENTER.
};

#endif // MAINWINDOW_H
