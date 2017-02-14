#pragma once
#include "domain.h"
class Repository
{
private:
	std::vector<Subject> subjects;
	int size;
public:
	void addSubject(Subject newSubj);
	void removeSubject(Subject subj);
	Subject& findByName(std::string nameOfSubj);
	void addHours(std::string nameOfSubj, std::string desc, int nrHours);
	void changeName(std::string oldName, std::string newName);
	void readFile(std::string fileName);
	void writeTofile(std::string fileName);
	std::vector<Subject>& getVector();
	Repository();
	~Repository();
};

