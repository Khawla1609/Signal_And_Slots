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
 *left=(*left)*(*right);
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
    disp->display((*left)*(*right));

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
