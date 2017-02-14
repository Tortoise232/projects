#include "Controller.h"

void Controller::addSubject(std::string name)
{
	Subject newSubject;
	newSubject.setSize(0);
	newSubject.setName(name);
	this->repo.addSubject(newSubject);
}

void Controller::removeSubject(std::string name)
{
	Subject newSubject = this->repo.findByName(name);
	this->repo.removeSubject(newSubject);
}

void Controller::addHours(std::string name, std::string desc,int nrHours)
{
	this->repo.addHours(name, desc, nrHours);
}

void Controller::changeName(std::string oldName, std::string newName)
{
	this->repo.changeName(oldName, newName);
}

std::vector<Subject>& Controller::getVector()
{
	return this->repo.getVector();
}

Subject& Controller::findByName(std::string name)
{
	return this->repo.findByName(name);
}

void Controller::writeToFile(std::string file) {
	this->repo.writeTofile(file);
}

Controller::Controller()
{
	Repository newRepo;
	this->repo = newRepo;
}


Controller::~Controller()
{
}
