#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwidget.h>
#include <qpainter.h>
#include <qpoint.h>
#include "graph.h"
#include <QString>
#include "cmath"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Graphmtx<int,double> g;
    Node m1,m2;
    void paintEvent(QPaintEvent*);
    int flagbutton=0;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};





#endif // MAINWINDOW_H
