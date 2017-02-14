#include "hoursPopout.h"



hoursPopout::hoursPopout(Controller& ctrl, std::string nameOfSubject, QWidget* parent) : ctrl(ctrl), nameOfSubject(nameOfSubject) 
{
	this->initGUI();
	this->connectSignalSlots();
	this->setWindowTitle(QString::fromStdString("~Add to " + nameOfSubject + "~"));
}


hoursPopout::~hoursPopout()
{
}

void hoursPopout::initGUI()
{
	QFormLayout* mainLay = new QFormLayout{ this };
	QLabel* description = new QLabel{ "Description:" };
	this->description = new QLineEdit();
	this->hours = new QSpinBox();
	this->addHours = new QPushButton{ "Add Hours" };
	mainLay->addWidget(description);
	mainLay->addWidget(this->description);
	mainLay->addWidget(this->hours);
	mainLay->addWidget(this->addHours);
}

void hoursPopout::connectSignalSlots()
{
	QObject::connect(this, SIGNAL(closeSignal()), this, SLOT(close()));
	QObject::connect(this->addHours, SIGNAL(clicked()), this, SLOT(addHandler()));
}

void hoursPopout::addHandler()
{
	std::string desc = this->description->text().toStdString();
	int nrHours = this->hours->text().toInt();
	this->ctrl.addHours(this->nameOfSubject, desc, nrHours);
	emit(closeSignal());
}