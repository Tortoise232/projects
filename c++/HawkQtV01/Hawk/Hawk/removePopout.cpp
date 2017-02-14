#include "removePopout.h"

void removePopout::initGUI()
{
	QFormLayout* mainLay = new QFormLayout{ this };
	QLabel* text = new QLabel{ QString::fromStdString("Do you really want to delete " +  this->name) };
	mainLay->addWidget(text);
	QWidget* buttonsWidget = new QWidget;
	QGridLayout* buttons = new QGridLayout{ buttonsWidget };
	this->yes = new QPushButton{ "Delete" };
	this->no = new QPushButton{ "Cancel" };
	buttons->addWidget(this->yes, 0, 0);
	buttons->addWidget(this->no, 0, 1);
	mainLay->addWidget(buttonsWidget);
}

void removePopout::connectSignalSlots()
{
	QObject::connect(this->no, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(this->yes, SIGNAL(clicked()), this, SLOT(removeHandler()));
	QObject::connect(this, SIGNAL(closeSignal()), this, SLOT(close()));
}

removePopout::~removePopout()
{
}

void removePopout::removeHandler()
{
	this->ctrl.removeSubject(this->name);
	emit(closeSignal());
}