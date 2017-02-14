#pragma once
#include "hawk.h"
class addPopout : public QWidget
{
	Q_OBJECT


public:
	addPopout(Controller& coreCtrl,QWidget* parent = 0);
	~addPopout();
	void connectSignalSlots();
private:
	Controller& ctrl;
	QLineEdit* subject;
	QPushButton* add;
	QLineEdit* colour;
signals:
	void closeSignal();
public slots:
	void initGUI();
	void addHandler();
	
};

