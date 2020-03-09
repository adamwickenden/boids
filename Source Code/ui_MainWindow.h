/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *SimulateButton;
    QSpinBox *ObstacleEdit;
    QSpinBox *PreyEdit;
    QSpinBox *PredatorEdit;
    QPushButton *AddOButton;
    QPushButton *RemoveOButton;
    QPushButton *AddPButton;
    QPushButton *RemovePButton;
    QPushButton *AddPrButton;
    QPushButton *RemovePrButton;
    QPushButton *CloseButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(522, 285);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 111, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 101, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 101, 16));
        SimulateButton = new QPushButton(centralWidget);
        SimulateButton->setObjectName(QStringLiteral("SimulateButton"));
        SimulateButton->setGeometry(QRect(80, 170, 151, 51));
        ObstacleEdit = new QSpinBox(centralWidget);
        ObstacleEdit->setObjectName(QStringLiteral("ObstacleEdit"));
        ObstacleEdit->setGeometry(QRect(140, 20, 42, 22));
        PreyEdit = new QSpinBox(centralWidget);
        PreyEdit->setObjectName(QStringLiteral("PreyEdit"));
        PreyEdit->setGeometry(QRect(140, 70, 42, 22));
        PredatorEdit = new QSpinBox(centralWidget);
        PredatorEdit->setObjectName(QStringLiteral("PredatorEdit"));
        PredatorEdit->setGeometry(QRect(140, 120, 42, 22));
        AddOButton = new QPushButton(centralWidget);
        AddOButton->setObjectName(QStringLiteral("AddOButton"));
        AddOButton->setGeometry(QRect(250, 20, 75, 23));
        RemoveOButton = new QPushButton(centralWidget);
        RemoveOButton->setObjectName(QStringLiteral("RemoveOButton"));
        RemoveOButton->setGeometry(QRect(370, 20, 101, 23));
        AddPButton = new QPushButton(centralWidget);
        AddPButton->setObjectName(QStringLiteral("AddPButton"));
        AddPButton->setGeometry(QRect(250, 70, 75, 23));
        RemovePButton = new QPushButton(centralWidget);
        RemovePButton->setObjectName(QStringLiteral("RemovePButton"));
        RemovePButton->setGeometry(QRect(370, 70, 101, 23));
        AddPrButton = new QPushButton(centralWidget);
        AddPrButton->setObjectName(QStringLiteral("AddPrButton"));
        AddPrButton->setGeometry(QRect(250, 120, 75, 23));
        RemovePrButton = new QPushButton(centralWidget);
        RemovePrButton->setObjectName(QStringLiteral("RemovePrButton"));
        RemovePrButton->setGeometry(QRect(370, 120, 101, 23));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(300, 170, 111, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 522, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Number of Obstacles", 0));
        label_2->setText(QApplication::translate("MainWindow", "Number of Prey", 0));
        label_3->setText(QApplication::translate("MainWindow", "Number of Predators", 0));
        SimulateButton->setText(QApplication::translate("MainWindow", "Simulate", 0));
        AddOButton->setText(QApplication::translate("MainWindow", "Add Obstacle", 0));
        RemoveOButton->setText(QApplication::translate("MainWindow", "Remove Obstacle", 0));
        AddPButton->setText(QApplication::translate("MainWindow", "Add Prey", 0));
        RemovePButton->setText(QApplication::translate("MainWindow", "Remove Prey", 0));
        AddPrButton->setText(QApplication::translate("MainWindow", "Add Predator", 0));
        RemovePrButton->setText(QApplication::translate("MainWindow", "Remove Predator", 0));
        CloseButton->setText(QApplication::translate("MainWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
