#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QTime"
#include"QLCDNumber"
#include"QTimerEvent"
#include"QHBoxLayout"
QT_BEGIN_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
void updateTime();
//void timeEvent(QTimerEvent *e)override;
void createwidget();
void placewidget();
void timerEvent(QTimerEvent *e)override;
private:

    QLCDNumber *hour;
    QLCDNumber *minute;
    QLCDNumber *second;

};
#endif // MAINWINDOW_H
