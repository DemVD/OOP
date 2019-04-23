#include <string.h>
#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatbot.h"
#include <iostream>

using namespace std;
using namespace ChatBot_NS;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Горячие клавишы - сочетание Ctrl + Enter
    //keyCtrlEnter = new QShortcut(this); // Инициализируем объект
    //keyCtrlEnter->setKey(Qt::CTRL + Qt::Key_Enter); // Устанавливаем сочетание кнопок
    // цепляем обработчик нажатия клавиши
    //connect(keyCtrlEnter, SIGNAL(activated()), this, SLOT(slotShortCutCtrlEnter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_sendMsg_clicked(){
    QString QStr = ui->textEdit->toPlainText();
    int QStrLen = QStr.length();
    ui->textEdit->setText(""); // после отправки сообщения окно очищается.
    ui->textBrowser_chat->append(QStr); // с каждым нажатием ОТПРАВИТЬ запись идет в новую строку.
    // 37 - max chatbox len
    if(QStrLen > 37){ // we must keep the date and sender on the same line with the sended msg
        int Lim = ceil(QStrLen);
        for(int i=0;i<Lim;i++){
            ui->textBrowser_nameTime->append("");
        }
    }
    ui->textBrowser_nameTime->append(QTime::currentTime().toString()); // len 8 = max len
    ui->textBrowser_nameTime->append(QString::fromStdString(CB.userName())); // len 8 = max len
}
/*
void MainWindow::slotShortCutCtrlEnter(){
    if(ui->textEdit->toPlainText().length() > 0){
        on_pushButton_sendMsg_clicked();
    }
}
*/
