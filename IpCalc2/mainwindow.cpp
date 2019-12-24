#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    //ui->treeWidget->setColumnCount(2);
    //ui->treeWidget->setHeaderLabel("Col A"); // changes name, one by one after each call
    //ui->treeWidget->setHeaderLabels(QStringList() << "one"<<"TWO"<<"3");


    /*
    addRoot("1 hello", "world");
    addRoot("2 hello", "world");
    addRoot("3 hello", "world");
    */
}

void MainWindow::addRoot(QString name, QString descr){
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    // Now we modify the item directly
    /*
    item->setText(0, name);
    item->setText(1, descr);
    ui->treeWidget->addTopLevelItem(item);

    addChild(item, "one", "hi");
    addChild(item, "TWO", "hi");
    */
}


void MainWindow::addChild(QTreeWidgetItem *parent, QString name, QString descr){
    //QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget); //top level addin
    QTreeWidgetItem *item = new QTreeWidgetItem();

    item->setText(0, name);
    //item->setText(1, descr);
    parent->addChild(item);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionNew_triggered(){
    // OK clicked
    bool ok;
    // input string
    QString inpstr = QInputDialog::getText(nullptr, "New", "IPv4 CIDR: ",
                                          QLineEdit::Normal, "", &ok);
    if(ok){
        QStringList strspl = inpstr.split('/');
        if(ip.setIpAdr( (strspl[0])) && ((strspl[1].toInt() > 0) && ((strspl[1].toInt() < 32))) ){
            ip.setCIDR_Mask_Bits(strspl[1].toInt());
            QString str = "Created new IP:"+ip.getIpNum(); // status bar message
            ui->statusbar->showMessage(str,delayMS);

            // After creation, clear ui, make new tree
            ui->treeWidget->clear();
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,"TEXT DUMMY HEA XD\nxD\n\nxDxD");
            ui->treeWidget->addTopLevelItem(item);
            ui->treeWidget->setHeaderLabel("");
        }
        else{
            QString str = "Failed to create IP:"+inpstr+" check input."; // status bar message
            ui->statusbar->showMessage(str,delayMS);
        }
    }

}

void MainWindow::on_actionExit_triggered(){
    QCoreApplication::quit();
}

/*
void MainWindow::on_pushButton_clicked(){
    ui->treeWidget->currentItem()->setText(0,ip.getIpNum());
    qDebug()<<ip.setIpAdr("127.198.0.16");
    qDebug()<<ip.getIpNum();
    ui->treeWidget->currentItem()->setBackgroundColor(0,Qt::red);
    ui->treeWidget->currentItem()->setBackgroundColor(1,Qt::blue);
} */
