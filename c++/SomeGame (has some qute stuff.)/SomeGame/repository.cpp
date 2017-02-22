#pragma once
#include "repository.h"
#include <fstream>
void Repository::addWord(std::string word)
{
	this->words.push_back(word);
}

std::string& Repository::find(std::string word)
{
	auto it = std::find(this->words.begin(), this->words.end(), word);
	return *it;
}

void Repository::addGuessed(std::string word)
{
	this->guessed.push_back(word);
}

void Repository::remove(std::string word)
{
	auto it = std::find(this->words.begin(), this->words.end(), find(word));
	this->addGuessed(*it);
	this->words.erase(it);
}

void Repository::saveGame(int score)
{
	std::ofstream out;
	out.open("save.txt");
	out << score << "\n";
	for (auto word : this->guessed)
		out << word.c_str() << ",";
	out.close();
}

void Repository::loadFile()
{
	std::ifstream in;
	std::string raw;
	in.open("word.txt");
	while (!in.eof())
	{
		getline(in, raw);
		if(raw.size() > 1)
			this->addWord(raw);
	}
	in.close();
}

