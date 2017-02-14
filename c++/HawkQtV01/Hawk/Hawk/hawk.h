#ifndef HAWK_H
#define HAWK_H
#pragma once
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QListWidget>
#include <QSpinBox>
#include <QtWidgets/QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "ui_hawk.h"
#include "Controller.h"
#include "popOuts.h"
#include "addPopout.h"
#include"hoursPopout.h"
#include "removePopout.h"
class Hawk : public QWidget
{
	Q_OBJECT

public:
	void initGUI();
	
	void connectSignalSlots();
	Hawk(QWidget *parent = 0);
	~Hawk();

private:
	QPushButton* addButton;
	QPushButton* increaseHours;
	QPushButton* popOut;
	QPushButton* remove;
	QListWidget* subjectList;
	Controller controller;
	Ui::HawkClass ui;

signals:
	void subjectListChange();

public slots:
void addButtonHandler() ;
void increaseHoursButtonHandler() ;
void popOutButtonHandler() ;
void populateList();
void removeHandler();

};

#endif // HAWK_H

