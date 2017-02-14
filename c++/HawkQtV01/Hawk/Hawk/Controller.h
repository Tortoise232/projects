#pragma once
#include "Repository.h"
class Controller
{
private: 
	Repository repo;
public:
	void addSubject(std::string name);
	void addHours(std::string name,std::string desc, int nrHours);
	void removeSubject(std::string name);
	void changeName(std::string oldName, std::string newName);
	void writeToFile(std::string file);
	Subject& findByName(std::string name);
	std::vector<Subject>& getVector();
	Controller();
	~Controller();
};

