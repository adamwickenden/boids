#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include "Storage.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow( int nObstacle, int nPrey, int nPredator, QWidget *parent = 0);
    ~DisplayWindow();

    //Input parameter methods
    void AddPrey();
    void AddObstacle();
    void AddPredator();
    void RemovePrey();
    void RemoveObstacle();
    void RemovePredator();

private slots:
    //Painting and simulation update slots
    void paintEvent(QPaintEvent *);
    void Run();

private:
    //Input parameters
    Ui::DisplayWindow *ui;
    int fnObstacle, fnPrey, fnPredator;
    Storage *fStore;
};

#endif // DISPLAYWINDOW_H
