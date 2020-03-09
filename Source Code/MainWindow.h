#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DisplayWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots://Allows user control with inputs.

    void on_SimulateButton_clicked();

    void on_AddOButton_clicked();

    void on_RemoveOButton_clicked();

    void on_AddPButton_clicked();

    void on_RemovePButton_clicked();

    void on_AddPrButton_clicked();

    void on_RemovePrButton_clicked();

    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui;
    DisplayWindow *fWin;
    bool close;
};

#endif // MAINWINDOW_H
