#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DisplayWindow.h"

//contructors
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SimulateButton_clicked()//COnnects simulate button to running display window
{
    fWin = new DisplayWindow(ui->ObstacleEdit->value(), ui->PreyEdit->value() , ui->PredatorEdit->value());
}

void MainWindow::on_AddOButton_clicked()
{
    fWin->AddObstacle();
}

void MainWindow::on_RemoveOButton_clicked()
{
    fWin->RemoveObstacle();
}

void MainWindow::on_AddPButton_clicked()
{
    fWin->AddPrey();
}

void MainWindow::on_RemovePButton_clicked()
{
    fWin->RemovePrey();
}

void MainWindow::on_AddPrButton_clicked()
{
    fWin->AddPredator();
}

void MainWindow::on_RemovePrButton_clicked()
{
    fWin->RemovePredator();
}

void MainWindow::on_CloseButton_clicked()
{
    fWin->~DisplayWindow();
}

