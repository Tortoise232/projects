#pragma once
#include <QLineEdit>
#include <QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QListWidget>
#include <QtWidgets/QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "domain.h"
class subjectInfoWindow : public QWidget
{
	Q_OBJECT
public:
	Subject subject;
	subjectInfoWindow(Subject givenSubj)
	{
		this->subject = givenSubj;
		this->initGUI();
		this->setWindowTitle(QString::fromStdString("~Info on " + this->subject.getName() + "~"));
	};
	~subjectInfoWindow() { this->initGUI(); };
	subjectInfoWindow() {};
	void initGUI()
	{
		QFormLayout* mainLayout = new QFormLayout{ this };
		QListWidget* hours = new QListWidget;
		std::vector<std::string> hoursUnprocessed = this->subject.getElements();
		for (auto lineUnprocessed : hoursUnprocessed)
		{
			QString newItem = QString::fromStdString(lineUnprocessed);
			hours->addItem(newItem);
		}
		mainLayout->addRow(hours);
	}
	
};
