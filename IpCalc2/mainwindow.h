#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTreeWidget>
#include <QtCore>
#include <QtGui>
#include <QInputDialog>
#include "ipclass.h"


QT_BEGIN_NAMESPACE
namespace Ui{
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    // Constructor, destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Functions
    void addRoot(QString name, QString descr);
    void addChild(QTreeWidgetItem *parent, QString name, QString descr);


private slots:
    void on_actionNew_triggered();
    void on_actionExit_triggered();

    void on_actionSeparate_triggered();

private:
    Ui::MainWindow *ui;
    IpAdr ip;
    // Status bar message delay in ms
    int delayMS = 12000;
};


#endif // MAINWINDOW_H
