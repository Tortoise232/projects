#include "hawk.h"

Hawk::Hawk(QWidget *parent): QWidget(parent)
{

	this->initGUI();
	this->connectSignalSlots();
	this->populateList();
}

Hawk::~Hawk()
{

}


void Hawk::initGUI()
{
	QGridLayout* mainLayout = new QGridLayout{ this };
	
	//middle
	QWidget* middleSide = new QWidget;
	QFormLayout* buttonLayoutM = new QFormLayout{ middleSide };
	this->addButton = new QPushButton{ "New task" };
	this->increaseHours = new QPushButton{ "Add hours" };
	this->subjectList = new QListWidget;
	this->subjectList->setSelectionMode(QAbstractItemView::SingleSelection);
	this->popOut = new QPushButton{ "Show info" };
	this->remove = new QPushButton{ "Remove" };
	buttonLayoutM->addWidget(this->addButton);
	buttonLayoutM->addWidget(this->increaseHours);
	buttonLayoutM->addWidget(this->popOut);
	buttonLayoutM->addWidget(this->remove);
	mainLayout->addWidget(this->subjectList, 0, 0);
	mainLayout->addWidget(middleSide, 0, 1);
	
}

void Hawk::connectSignalSlots()
{	
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addButtonHandler()));
	QObject::connect(this->popOut, SIGNAL(clicked()), this, SLOT(popOutButtonHandler()));
	QObject::connect(this->increaseHours, SIGNAL(clicked()), this, SLOT(increaseHoursButtonHandler()));
	QObject::connect(this, SIGNAL(subjectListChange()), this, SLOT(populateList()));
	QObject::connect(this->remove, SIGNAL(clicked()), this, SLOT(removeHandler()));
}



void Hawk::addButtonHandler()
{
	addPopout* addWindow = new addPopout{ this->controller };
	addWindow->show();
	QObject::connect(addWindow, SIGNAL(closeSignal()), this, SLOT(populateList()));
}

void Hawk::increaseHoursButtonHandler()
{
	std::string nameOfSubject = this->subjectList->selectedItems()[0]->text().toStdString();
    std::size_t spaceChar = nameOfSubject.find(" ");
	nameOfSubject = nameOfSubject.substr(0, spaceChar);
	hoursPopout* adder = new hoursPopout(this->controller, nameOfSubject);
	adder->show();
	QObject::connect(adder, SIGNAL(closeSignal()), this, SLOT(populateList()));
}

void Hawk::popOutButtonHandler()
{
	std::string selectedStr = this->subjectList->selectedItems()[0]->text().toStdString();
	std::size_t spaceChar = selectedStr.find(" ");
	selectedStr = selectedStr.substr(0, spaceChar);
	Subject toBeShown = this->controller.findByName(selectedStr);
	subjectInfoWindow* hello = new subjectInfoWindow(toBeShown);
	hello->show();
}

void Hawk::removeHandler()
{
	std::string selectedStr = this->subjectList->selectedItems()[0]->text().toStdString();
	std::size_t spaceChar = selectedStr.find(" ");
	selectedStr = selectedStr.substr(0, spaceChar);
	removePopout* removeWindow = new removePopout(this->controller, selectedStr);
	removeWindow->show();
	QObject::connect(removeWindow, SIGNAL(closeSignal()), this, SLOT(populateList()));
}

void Hawk::populateList()
{
	if (this->subjectList > 0)
		this->subjectList->clear();
	std::vector<Subject> subjects = this->controller.getVector();
	for (auto subject : subjects)
	{
		QString subjectToString = QString::fromStdString(subject.toString());
		this->subjectList->addItem(subjectToString);
	}
	if (this->subjectList > 0)
		this->subjectList->setCurrentRow(0);

	this->controller.writeToFile("data.txt");
}
