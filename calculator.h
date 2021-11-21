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
