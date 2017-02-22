/********************************************************************************
** Form generated from reading UI file 'somegame.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOMEGAME_H
#define UI_SOMEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SomeGameClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SomeGameClass)
    {
        if (SomeGameClass->objectName().isEmpty())
            SomeGameClass->setObjectName(QStringLiteral("SomeGameClass"));
        SomeGameClass->resize(600, 400);
        menuBar = new QMenuBar(SomeGameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SomeGameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SomeGameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SomeGameClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SomeGameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SomeGameClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SomeGameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SomeGameClass->setStatusBar(statusBar);

        retranslateUi(SomeGameClass);

        QMetaObject::connectSlotsByName(SomeGameClass);
    } // setupUi

    void retranslateUi(QMainWindow *SomeGameClass)
    {
        SomeGameClass->setWindowTitle(QApplication::translate("SomeGameClass", "SomeGame", 0));
    } // retranslateUi

};

namespace Ui {
    class SomeGameClass: public Ui_SomeGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOMEGAME_H
