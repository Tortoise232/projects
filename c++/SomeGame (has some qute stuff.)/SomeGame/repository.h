#pragma once
#include <vector>
#include <string>
class Repository
{
private:
	std::vector<std::string> words;
	std::vector<std::string> guessed;
public:
	Repository(std::vector<std::string> words,std::vector<std::string> guessed)
	{
		this->words = words;
		this->guessed = guessed;
	};
	std::vector<std::string>& getVector() { return this->words; }
	std::vector<std::string>& getGuessed() { return this->guessed; }
	Repository() {};
	~Repository() {};
	void addWord(std::string word);
	void addGuessed(std::string word);
	void loadFile();
	void remove(std::string word);
	std::string& find(std::string word);
	void saveGame(int score);
};