/********************************************************************************
** Form generated from reading UI file 'hawk.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAWK_H
#define UI_HAWK_H

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

class Ui_HawkClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HawkClass)
    {
        if (HawkClass->objectName().isEmpty())
            HawkClass->setObjectName(QStringLiteral("HawkClass"));
        HawkClass->resize(600, 400);
        menuBar = new QMenuBar(HawkClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HawkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HawkClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HawkClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HawkClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HawkClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HawkClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HawkClass->setStatusBar(statusBar);

        retranslateUi(HawkClass);

        QMetaObject::connectSlotsByName(HawkClass);
    } // setupUi

    void retranslateUi(QMainWindow *HawkClass)
    {
        HawkClass->setWindowTitle(QApplication::translate("HawkClass", "Hawk", 0));
    } // retranslateUi

};

namespace Ui {
    class HawkClass: public Ui_HawkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAWK_H
