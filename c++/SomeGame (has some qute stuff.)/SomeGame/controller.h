#pragma once
#include "repository.h"
class Controller
{
private:
	Repository repo;
public:
	Controller(){};
	~Controller() {};
	std::vector<std::string>& getRepo() { return this->repo.getVector() };
	std::vector<std::string>& getGuessed() { return this->repo.getGuessed() };
	void remove(std::string word);
	bool checkWord(std::string word, std::string other);
	std::string scramble(std::string initWord);

	
};