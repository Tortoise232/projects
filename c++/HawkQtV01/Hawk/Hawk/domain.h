#pragma once
#include <vector>
#include <string>
class Subject
{
private:
	std::string name;
	std::vector<std::string> elements;
	int size;
public:
	/*Returns how many hours have been invested in the subject
		input: - 
		output: integer representing the number of hours
		prec: -
		postc: -*/
	int getSize();
	/*Updates the number of hours invested in a subject
		input: integer representing the new number of hours
		output: -
		prec: -
		postc: the newSize should reflect the length of the std vector representing the elements*/
	void setSize(int newSize);
	std::string getName();
	void setName(std::string newName);
	/*Adds a number of string to the elements vector, adds hours to a given subject, giving each of the hours the same description
	input: string representing the description of the invested hours, integer nrHours representing the hours invested
	output: -
	prec: int nrHours > 0
	postc: vector size += 2, desc string added to the vector nrHours times*/
	void addHours(std::string desc, int nrHours);
	/*Overload equality for obvious reasons*/
	bool operator==(Subject otherSub)
	{
		if (this->elements.size() != otherSub.getSize())
			return 0;
		if (this->elements != otherSub.elements)
			return 0;
		return 1;
	}
	std::string toString();
	std::vector<std::string>& getElements();
	Subject();
	~Subject();
};

