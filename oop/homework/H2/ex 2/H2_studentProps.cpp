#include "H2_studentFct.h"
#include <iostream>
void student::setName()
{
	std::cout << "the student, "; 
	
	char elem = 0, index_name = 0;
	while (elem != '.')
	{
		std::cin >> elem;
		if (elem != '.')
			this->name[(int)index_name++] = elem;
	}
}
char* student::getName()
{
	if (this->name[0] == 0)
		std::cout << "name not set\n";
	return this->name;
}

void student::setMTH()
{
	std::cout << "math grade: ";
	std::cin >> this->marks[mathematics];
	return;
}
float student::getMTH()
{
	if (this->marks[mathematics] == -1)
		std::cout << "grade not set\n";
	return this->marks[mathematics];
}

void student::setENG()
{
	std::cout << "english grade: ";
	std::cin >> this->marks[english];
}
float student::getENG() 
{
	if (marks[english] == -1)
		std::cout << "grade not set\n";
	return this->marks[english];
}

void student::setHST()
{
	std::cout << "history grade: ";
	std::cin >> this->marks[history];
}
float student::getHST()
{
	if (marks[history] == -1)
		std::cout << "grade not set\n";
	return this->marks[history];
}

float student::average_grade()
{
	float s = 0;
	for (int i = 0; i < 3; i++)
	{
		if (marks[i] == -1)
		{
			std::cout << "grades not set\n";
			return 0;
		}
		s += this->marks[i];

	}
	return s / 3;
}