#include "addPopout.h"



addPopout::addPopout(Controller& coreCtrl, QWidget* parent) : ctrl(coreCtrl)
{
	this->initGUI();
	this->connectSignalSlots();
	this->setWindowTitle("~Add~");
}

void addPopout::initGUI()
{
	QFormLayout* mainLay = new QFormLayout{ this };
	QLabel* nameLabel = new QLabel{ "Name:" };
	this->subject = new QLineEdit();
	nameLabel->setBuddy(this->subject);
	this->colour = new QLineEdit();
	QLabel* colourLabel = new QLabel{ "Colour:" };
	colourLabel->setBuddy(this->colour);
	mainLay->addRow(nameLabel, subject);
	mainLay->addRow(colourLabel, colour);
	this->add = new QPushButton{ "Add" };
	mainLay->addWidget(this->add);
}

void addPopout::connectSignalSlots()
{
	QObject::connect(this->add, SIGNAL(clicked()), this, SLOT(addHandler()));
	QObject::connect(this, SIGNAL(closeSignal()), this, SLOT(close()));

}



addPopout::~addPopout()
{
}

void addPopout::addHandler()
{
	this->ctrl.addSubject(this->subject->text().toStdString());
	emit(closeSignal());
}