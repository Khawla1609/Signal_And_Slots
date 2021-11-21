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
QEvent *event;
QKeyEvent *e;
};


#endif
