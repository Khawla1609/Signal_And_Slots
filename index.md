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

to have a result, you must follow the following steps

1-Download the starter code <a href="index.html">TrafficLight.zip</a>

2-Investigate the code in order to underhand each component of the TrafficLight class.

3-Your task is add some functions in order to change each 3 sedonds in the following order:

 ```cpp
 Red -> Green -> Yellow
 
 ```
 you will find the complete code below:
 
**.Header**
  ```cpp
  #ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QWidget>
#include"QTimer"
#include"QVector"
class QRadioButton;

class TrafficLight: public QWidget{
  Q_OBJECT

public:

  TrafficLight(QWidget * parent = nullptr);

protected:
     void createWidgets();
     void placeWidgets();
     void makeconnection();
void timerEvent(QTimerEvent *e) override;
void keyPressEvent(QKeyEvent *d)override;
private:

  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
  QVector<QRadioButton*> lights;
  int index;
int curent;
int l=0;
QTimer *timer;
};


#endif
 ```
**.cpp**
 ```cpp
 #include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include "QTimer"
#include"QApplication"
#include"QKeyEvent"
TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){
QEvent* event;
QKeyEvent*e;

    //Creatign the widgets
    createWidgets();

    //place Widgets
    placeWidgets();
makeconnection();
     curent=0;
//    if (event->type()!=QEvent::KeyPress)
//    startTimer(1000);
    if(event->type()!=QEvent::KeyPress)
    {
        startTimer(1000);
    }
    else
    {
        timer->stop();

    }

}

void TrafficLight::createWidgets()
{
    if(l==1)
        startTimer(1000);
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
  timer = new QTimer(this);
}


void TrafficLight::placeWidgets()
{


  // Placing the widgets
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
  setLayout(layout);
}
void TrafficLight::timerEvent(QTimerEvent *e){

//    bool enfonce=true;

//    index=(index +1)%3;
//    lights[index]->toggle();

    curent++;
    if(redlight->isChecked() && curent==4)
    {
        yellowlight->toggle();
        curent=0;
    }
    if(yellowlight->isChecked() && curent==1)
    {
        greenlight->toggle();
        curent=0;
    }

    if(greenlight->isChecked() && curent==5)
    {

        redlight->toggle();
        curent=0;

    }

}
void TrafficLight::keyPressEvent(QKeyEvent *d)
{

curent++;
    if (d->key() == Qt::Key_Escape)
        qApp->exit();
    if (d->key() == Qt::Key_R )
    {
         redlight->toggle();
//        index=0;
//      lights[index]->toggle();
}
    if (d->key() == Qt::Key_Y)
    {
       yellowlight->toggle();
//         index=1;
//        lights[index]->toggle();
    }
    if (d->key() == Qt::Key_G)
    {
            greenlight->toggle();
//         index=2;
//        lights[index]->toggle();
}

    if(d->key() == Qt::Key_E)
  l++;
}
void TrafficLight::makeconnection(){
//     connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
}

```

 **main**
 ```cpp
 #include <QApplication>
#include "trafficlight.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Creating the traffic light
    auto light = new TrafficLight;


    //showing the trafic light
    light->show();

    return a.exec();
}

```
