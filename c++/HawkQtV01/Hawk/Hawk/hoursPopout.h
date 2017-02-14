#pragma once
#include "hawk.h"
class hoursPopout : public QWidget
{
	Q_OBJECT
public:
	hoursPopout(Controller& ctrl,std::string nameOfSubject,QWidget* parent = 0);
	~hoursPopout();
	void connectSignalSlots();

private:
	Controller& ctrl;
	std::string nameOfSubject;
	QLineEdit* description;
	QSpinBox* hours;
	QPushButton* addHours;

signals:
	void closeSignal();

public slots:
	void initGUI();
	void addHandler();

};

