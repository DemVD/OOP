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
            QStringList stli = ip.displayIpInfo();
            QString text = "\n"+stli[0]+"\n"+stli[1]+"\n"+stli[2]+"\n"+stli[3]+"\n"+stli[4]+"\n"+stli[5]+"\n";
            item->setText(0,text);
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

void MainWindow::on_actionSeparate_triggered(){
    QStringList qstrli;
    // OK clicked
    bool ok;
    // input string
    QString inpstr = QInputDialog::getText(nullptr, "Separate", "Enter how much hosts each subnet has to contain: ",
                                          QLineEdit::Normal, "", &ok);
    if(ok){
        if(inpstr.contains(',')){
            qstrli = inpstr.split(',');
        }
        else if(inpstr.contains(' ')){
            qstrli = inpstr.split(' ');
        }
        else if(inpstr.contains('.')||inpstr.contains('q')||inpstr.contains('w')||inpstr.contains('e')||inpstr.contains('r')
                ||inpstr.contains('t')||inpstr.contains('y')||inpstr.contains('u')||inpstr.contains('i')||inpstr.contains('o')
                ||inpstr.contains('p')){
            QString str = "Failed to split input. Separators: ','/' '.";
            ui->statusbar->showMessage(str,delayMS);
            return;
        }
        else{
            QString str = "Failed to split input. Separators: ','/' '.";
            ui->statusbar->showMessage(str,delayMS);
            return;
        }
        ip.splitNet2Subnets(qstrli);
    }
}

/*
void MainWindow::on_pushButton_clicked(){
    ui->treeWidget->currentItem()->setText(0,ip.getIpNum());
    qDebug()<<ip.setIpAdr("127.198.0.16");
    qDebug()<<ip.getIpNum();
    ui->treeWidget->currentItem()->setBackgroundColor(0,Qt::red);
    ui->treeWidget->currentItem()->setBackgroundColor(1,Qt::blue);
} */
