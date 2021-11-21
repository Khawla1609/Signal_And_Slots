#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include "QTimer"
#include"QApplication"
#include"QKeyEvent"
TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){



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
