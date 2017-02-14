#include "Repository.h"
#include <algorithm>
#include <fstream>
void Repository::addSubject(Subject newSubj)
{
	this->subjects.push_back(newSubj);
}

void Repository::removeSubject(Subject subj)
{
	Subject tempSubj;
	auto it = find(subjects.begin(), subjects.end(), subj);
	tempSubj = *it;
	subjects.erase(it);
}

Subject& Repository::findByName(std::string nameOfSubj)
{
	for (std::vector<Subject>::iterator it = this->subjects.begin(); it != this->subjects.end(); it++)
		if (nameOfSubj == it->getName())
			return *it;
	Subject* nullCase = new Subject();
	std::string null;
	null += "NULL";
	nullCase->setName(null);
	return *nullCase;

}

void Repository::addHours(std::string nameOfSubj, std::string desc, int nrHours)
{
	//Smart way lel
	auto it = find_if(this->subjects.begin(), this->subjects.end(), [&nameOfSubj](Subject& subj) {return subj.getName() == nameOfSubj;});
	it->addHours(desc, nrHours);
	//for (std::vector<Subject>::iterator it = this->subjects.begin(); it != this->subjects.end(); it++)
		//if (nameOfSubj == it->getName())
			//it->addHours(desc, nrHours);
}

void Repository::changeName(std::string oldName, std::string newName)
{
	auto it = find_if(this->subjects.begin(), this->subjects.end(), [&oldName](Subject& subj) {return subj.getName() == oldName;});
	it->setName(newName);
}

#include <sstream>
using namespace std;
std::vector<std::string> split(std::string input, char delim) {
	stringstream stream;
	stream << input;
	vector<string> res;
	for (int i = 0; i < 2; ++i) {
		string str;
		getline(stream, str, delim);
		res.push_back(str);
	}
	return res;
}

//refactor or understand lol
void Repository::readFile(std::string fileName)
{
	std::ifstream input;
	std::string processedInput;
	std::string badCase = "NULL";
	Subject carriageSubj;
	input.open(fileName);
	while (!input.eof())
	{
		getline(input, processedInput);
		if (processedInput.size() < 2)
			continue;
		std::vector<std::string> splitString = split(processedInput, ';');
		
		if (this->findByName(splitString[0]).getName() == badCase)
		{
			carriageSubj.setName(splitString[0]);
			this->addSubject(carriageSubj);
			this->addHours(splitString[0], splitString[1], 1);
		}
		else
			this->addHours(splitString[0], splitString[1], 1);
	}


}

void Repository::writeTofile(std::string fileName)
{
	std::ofstream outputFile;
	outputFile.open(fileName);
	std::vector<Subject> data = this->getVector();
	for (Subject subject : data)
	{
		for (std::string hour : subject.getElements())
		{
			outputFile << subject.getName() << ";" << hour<<"\n";

		}

	}
}
std::vector<Subject>& Repository::getVector()
{
	return this->subjects;
}

Repository::Repository()
{
	this->readFile("data.txt");
}

Repository::~Repository()
{
}
