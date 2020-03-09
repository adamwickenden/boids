#include <iostream>
#include <time.h>
#include <vector>
#include "PolarVector.h"
#include "Storage.h"
#include "Prey.h"
#include "Obstacle.h"

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
