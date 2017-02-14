#include "domain.h"



Subject::Subject()
{
	this->size = 0;
}

Subject::~Subject(){}

int Subject::getSize()
{
	return this->size;
}

void Subject::setSize(int newSize)
{
	this->size = newSize;
}

void Subject::addHours(std::string desc, int nrHours)
{
	for (int counter = 0; counter < nrHours; counter++)
	{
		this->elements.push_back(desc);
		this->size++;
	}
}

std::string Subject::getName()
{
	return this->name;
}

void Subject::setName(std::string newName)
{
	this->name = newName;
}

std::string Subject::toString()
{
	std::string toString = "";
	toString += this->getName();
	toString += " ";
	char sizeAsChar[5] = { 0 };
	itoa(this->getSize(), sizeAsChar, 10);
	toString += sizeAsChar;
	return toString;
}

std::vector<std::string>& Subject::getElements()
{
	return this->elements;
}