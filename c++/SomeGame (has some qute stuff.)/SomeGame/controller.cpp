#pragma once
#include "controller.h"
#include <stdlib.h>
void Controller::remove(std::string word)
{
	this->repo.remove(word);
}

bool checkWord(std::string word, std::string other)
{
	if (word.size() != other.size())
		return false;
	std::vector<char> letters;
	int counter = 0;
	while (counter < word.size())
		letters.push_back(word[counter]);
	counter = 0;
	while (counter < other.size())
	{
		auto it = std::find(letters.begin(), letters.end(), other[counter]);
		if (*it == NULL)
			return false;
	}
	return true;
}

std::string Controller::scramble(std::string initWord)
{
	std::vector<int> scramble;
	int counter = 0,aux,auxRand;
	while (counter < initWord.size())
	{
		scramble.push_back(counter);
		counter++;
	}
	for (counter = 0;counter < initWord.size();counter++)
	{
		aux = scramble[counter];
		auxRand = rand() % initWord.size() + 0;
		scramble[counter] = scramble[auxRand];
		scramble[auxRand] = aux;
		
	}
	std::string scrambledWord;
	for (counter = 0; counter < initWord.size();counter++)
		scrambledWord.push_back(initWord[scramble[counter]]);
	return scrambledWord;
}

