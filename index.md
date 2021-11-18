# Signal and Slots

<!-- link of TP -->

you can access the tp from then the following link [TP Signal and Slots](https://anassbelcaid.github.io/CS311/calculator/) 

<details>
  <summary>Table of Contents</summary>
  <ol>
     <li class="list-group-item"> <a href="#Calculator">Calculator </a></li>
    <ul>
        <li><a href="#Setup">Setup</a></li>
        <li><a href="#Custom Slots">Custom Slots</a></li>
        <li><a href="#Digits Interaction">Digits Interaction</a></li>
        <li><a href="#Integer numbers">Integer numbers</a></li>
        <li><a href="#Operation Interaction">Operation Interaction</a></li>
        <li><a href="#Enter Button">Enter Button</a></li>
        <li><a href="#Enhancements">Enhancements</a></li>
      </ul>
    <li><a href="#Traffic Light">Traffic Light</a></li>
    <li><a href="#Digital Clock">Digital Clock</a></li>
    
    
     
  </ol>
</details>


### Digital Clock

you will find below the three main classes of the code concerned Digital Clock.
the concept of this part is to run a current time using some special function ;

**.Header**
```cpp
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
```
**.cpp**
```cpp
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
```

 **main**
 ```cpp
 #include "mainwindow.h"

#include <QApplication>
#include"mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow;
    w->show();
    return a.exec();
}
 ```
 
### Traffic Light

The goal of the exercice is learn to,use the QTimer to simulate a traffic light  **Traffic Light**

   <p align="center">
    <img src="images/Traffic Light.png">
   </p>  
   <h2 align="center"> Traffic Light.</h2>
