#include "DisplayWindow.h"
#include "ui_DisplayWindow.h"

#include <QPainter>
#include <QTimer>
#include <QBrush>
#include <QColor>

#include <iostream>
#include <time.h>
#include <vector>
#include "PolarVector.h"


DisplayWindow::DisplayWindow(int nObstacle, int nPrey, int nPredator, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindow), fStore()//Initialises display window
{    
    ui->setupUi(this);
    //set input parameters
    fnObstacle = nObstacle;
    fnPrey = nPrey;
    fnPredator = nPredator;

    srand (time(NULL));//initalise time

    fStore = new Storage(nPrey, nObstacle, nPredator);//initialise store of all objects

    QTimer *timer = new QTimer(this);//run slot 1, paint event with time
    connect(timer, SIGNAL(timeout()), this, SLOT(paintEvent(QPaintEvent*)));
    timer->start(10);
    QTimer *timer2 = new QTimer(this);//run slot 2, Run with time
    connect(timer2, SIGNAL(timeout()), this, SLOT(Run()));
    timer2->start(10);
    show();
}

DisplayWindow::~DisplayWindow()
{

    fStore->~Storage();
    delete ui;

}

void DisplayWindow::paintEvent(QPaintEvent *){//displays all movement and images on screen
    QPainter painter(this);

    painter.fillRect(QRect(0,0, width() -1, height() - 1), QBrush(Qt::white));//paint white background

    for(int i = 0; i < fStore->GetSizeO(); i++){//paint obstacles to screen
        PolarVector positionOb = fStore->GetComponentO(i)->GetPosition();
        QColor green("#00ff50");
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush(green, style);
        painter.setBrush(brush);
        painter.drawEllipse((positionOb.GetX()-2.5), (positionOb.GetY()+2.5), 5, 5);
    }

    for(int i = 0; i < fStore->GetSizeP(); i++){//paint prey to screen
        PolarVector positionPr = fStore->GetComponentP(i)->GetPosition();
        QColor black("#000000");
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush(black, style);
        painter.setBrush(brush);
        painter.drawRect((positionPr.GetX() - 2.5), (positionPr.GetY() + 1.5), 3 , 3);
    }

    for(int i = 0; i < fStore->GetSizePr(); i++){//paint predators to screen
        PolarVector positionPred = fStore->GetComponentPr(i)->GetPosition();
        QColor red("#cc0202");
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush(red, style);
        painter.setBrush(brush);
        painter.drawRect((positionPred.GetX() - 2.5), (positionPred.GetY() + 2.5), 5 , 5);
    }
    this->update();
}

void DisplayWindow::Run(){//calls simulate of entire storage class
    fStore->Simulate();
}

void DisplayWindow::AddPrey(){

    fStore->AddPrey();
}

void DisplayWindow::AddObstacle(){

    fStore->AddObstacle();
}

void DisplayWindow::AddPredator(){

    fStore->AddPredator();
}

void DisplayWindow::RemovePrey(){
    fStore->RemovePrey();
}

void DisplayWindow::RemoveObstacle(){
    fStore->RemoveObstacle();
}

void DisplayWindow::RemovePredator(){
    fStore->RemovePredator();
}

