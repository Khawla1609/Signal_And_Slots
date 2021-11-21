#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QWidget(parent)

{

    createwidget();
placewidget();
updateTime();
startTimer(1000);
}
void MainWindow::createwidget(){
    hour=new QLCDNumber;
    hour->setDigitCount(2);
    minute=new QLCDNumber;
    minute->setDigitCount(2);
    second=new QLCDNumber;
    second->setDigitCount(2);
}
void MainWindow::placewidget(){
    QLayout *layout = new QHBoxLayout;
    setLayout(layout);
    layout->addWidget(hour);
     layout->addWidget(minute);
      layout->addWidget(second);
}
void MainWindow::updateTime(){
    auto T=QTime::currentTime();
    hour->display(T.hour());
     minute->display(T.minute());
      second->display(T.second());
}

void MainWindow::timerEvent(QTimerEvent *e){
    updateTime();
}
