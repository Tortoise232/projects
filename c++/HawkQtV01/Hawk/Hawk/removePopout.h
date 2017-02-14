#pragma once
#include "hawk.h"
class removePopout : public QWidget
{
	Q_OBJECT
public:
	removePopout(Controller& ctrl, std::string name) : ctrl(ctrl), name(name)
	{
		this->initGUI();
		this->connectSignalSlots();
		this->setWindowTitle("");
	}
	void initGUI();
	void connectSignalSlots();
	~removePopout();
private:
	Controller& ctrl;
	std::string name;
	QPushButton* yes;
	QPushButton* no;
signals:
	void closeSignal();
public slots:
	void removeHandler();
};

