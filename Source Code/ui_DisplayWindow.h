/********************************************************************************
** Form generated from reading UI file 'DisplayWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:

    void setupUi(QWidget *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName(QStringLiteral("DisplayWindow"));
        DisplayWindow->resize(1000, 700);

        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QWidget *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QApplication::translate("DisplayWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
