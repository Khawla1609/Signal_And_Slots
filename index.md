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
 https://user-images.githubusercontent.com/93408621/142759272-6ecd33d3-a205-485a-8bb5-ed18f48abcb9.mp4

 
### Traffic Light

The goal of the exercice is learn to,use the QTimer to simulate a traffic light  **Traffic Light**

   <p align="center">
    <img src="TrafficLight.PNG">
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

### calculator
 
  This exercise follows up to add interactive functionality to the calculator widgets written in the previous homework. The goal is to use Signals and Slots to simulate a basic calculator behavior. The supported operations are *, +, -, /.

   <p align="center">
    <img src="calculatrice.PNG">
   </p>  
   <h2 align="center"> calculator.</h2>


**.Header**

```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include <QLCDNumber>
using namespace std;
class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();




 // Add you custom slots here

protected:
    void createWidgets();        //Function to create the widgets
    void placeWidget();         // Function to place the widgets
    void makeConnexions();      // Create all the connectivity
     void makeConnexionss();      // Create all the connectivity

//events
protected:
    void keyPressEvent(QKeyEvent *e)override;     //Override the keypress events
public slots:
    void changeOperation();  //Slot to handle the click on operations
   void newDigit();
   void ent();
void reset();
private:
    QGridLayout *buttonsLayout; // layout for the buttons
    QVBoxLayout *layout;        //main layout for the button
    QVector<QPushButton*> digits;  //Vector for the digits

     int l;
//    int* lesvaleurs;
//     QString* lesoperateurs;
//      int o;
    QPushButton *enter;            // enter button
     QPushButton *c;            // enter button
    QVector<QPushButton*> operations; //operation buttons
    QLCDNumber *disp;             // Where to display the numbers
    QVector<QString*> vector;
    int * left;          //left operand
        int * right;         // right operand
        QString *operation;  // Pointer on the current operation
};
#endif // CALCULATOR_H

**.cpp**
```cpp
#include "calculator.h"
#include <QKeyEvent>
#include <QApplication>
#include<stdio.h>


Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{

operation = new QString();
    createWidgets();
    placeWidget();
    makeConnexions();
l=0;
}






Calculator::~Calculator()
{
    delete disp;
    delete layout;
    delete buttonsLayout;
}


void Calculator::createWidgets()
{
    //Creating the layouts
    layout = new QVBoxLayout();
    layout->setSpacing(2);

    //grid layout
    buttonsLayout = new QGridLayout;


    //creating the buttons
    for(int i=0; i < 10; i++)
    {
        digits.push_back(new QPushButton(QString::number(i)));
        digits.back()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        digits.back()->resize(sizeHint().width(), sizeHint().height());
    }
    //enter button
    enter = new QPushButton("Enter",this);
    enter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    enter->resize(sizeHint().width(), sizeHint().height());

    //reset button
    c = new QPushButton("C",this);
    c->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    c->resize(sizeHint().width(), sizeHint().height());
    //operatiosn buttons
    operations.push_back(new QPushButton("+"));
    operations.push_back(new QPushButton("-"));
    operations.push_back(new QPushButton("*"));
    operations.push_back(new QPushButton("/"));


    //creating the lcd
    disp = new QLCDNumber(this);
    disp->setDigitCount(6);

}

void Calculator::placeWidget()
{

    layout->addWidget(disp);
    layout->addLayout(buttonsLayout);


    //adding the buttons
    for(int i=1; i <10; i++)
        buttonsLayout->addWidget(digits[i], (i-1)/3, (i-1)%3);


    //Adding the operations
    for(int i=0; i < 4; i++)
        buttonsLayout->addWidget(operations[ i], i, 4);


    //Adding the 0 button
    buttonsLayout->addWidget(digits[0], 3, 0);
    buttonsLayout->addWidget(enter, 3, 1);
    buttonsLayout->addWidget(c, 3, 2);
    setLayout(layout);

}

void Calculator::makeConnexions()
{
    for(int i=0; i <10; i++){
        connect(digits[i], &QPushButton::clicked,
                this, &Calculator::newDigit);
  }
    for(int j=0;j <4; j++){
    connect(operations[j], &QPushButton::clicked,
                this, &Calculator::changeOperation);
    }
 connect(enter,&QPushButton::clicked,this,&Calculator::ent);
 connect(c,&QPushButton::clicked,this,&Calculator::reset);
}


void Calculator::keyPressEvent(QKeyEvent *e)
{
    //Exiting the application by a click on space
    if( e->key() == Qt::Key_Escape)
        qApp->exit(0);


    //You could add more keyboard interation here (like digit to button)
}
void Calculator::newDigit( )
{
    //getting the sender
    auto button = dynamic_cast<QPushButton*>(sender());

    //getting the value
    int value = button->text().toInt();

    //Check if we have an operation defined
    if(operation->isEmpty())
    {
        if(!left)
            left = new int{value};
        else
            *left = 10 * (*left) + value;

        disp->display(*left);

    }
else
    {

        //check if we have a value or not
        if(!right)
            right = new int{value};
        else
            *right = 10 * (*right) + value;

        disp->display(*right);

}
}
void Calculator::changeOperation()
{
if(vector.isEmpty()){
    //Getting the sender button
    auto button = dynamic_cast<QPushButton*>(sender());

    //Storing the operation
    operation = new QString{button->text()};
 vector << this->operation;
    //Initiating the right button
    right = new int{0};

    //reseting the display
    disp->display(0);}
else{
    //Getting the sender button
    auto button = dynamic_cast<QPushButton*>(sender());

    //Storing the operation
    operation = new QString{button->text()};
 vector << this->operation;

 if(vector.at(l)==QString("+"))
 *left=(*left)+(*right);
 if(vector.at(l)==QString("*"))
 left=(*left)(*right);
 if(vector.at(l)==QString("-"))
 *left=(*left)-(*right);
 if(vector.at(l)==QString("/"))
 *left=(*left)/(*right);
    //Initiating the right button
    right = new int{0};

    //reseting the display
    disp->display(*left);
    l++;
}
}
void Calculator::ent(){
    if(this->operation==QString("+"))
    disp->display((*left)+(*right));

    if(this->operation==QString("*"))
    disp->display((left)(*right));

    if(this->operation==QString("-"))
    disp->display((*left)-(*right));

    if(this->operation==QString("/"))
    disp->display((*left)/(*right));


}
void Calculator::reset(){
    *left=0;
    *right=0;
    operation=new QString();

        vector.clear();
l=0;
    disp->display(0);
}

```
 **main**
 ```cpp
 #include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowTitle("Calculator");
    w.resize(500,500);
    w.show();
    return a.exec();
}

```
https://user-images.githubusercontent.com/93408621/142764864-d191f6a0-701f-4ad9-a9df-29a27f57605e.mp4


