#include <iostream>
#include "H2_movie.h"
void Movie::set_name(const char input[])
{
	strcpy_s(this->name, input);
}
char* Movie::get_name()
{
	if (this->name[0] == 0)
		std::cout << "name not set.\n";
	return this->name;
}

void Movie::set_year(short input)
{
	this->release_year = input;
}
short Movie::get_year()
{
	if (this->release_year == 0)
		std::cout << "the release year is not set.\n";
	return this->release_year;
}

void Movie::set_score(double input)
{
	this->imdb_score = input;
}
double Movie::get_score()
{
	if (this->imdb_score == 0)
		std::cout << "the score is not set.\n";
	return this->imdb_score;
}

void Movie::set_length(char input)
{
	this->minutes_lenght = input;
}
char Movie::get_length()
{
	if (this->minutes_lenght == 0)
		std::cout << "we do not know how many minutes it takes.\n";
	return this->minutes_lenght;
}

int Movie::time_passed()
{
	if (Movie::get_year())
		return 2024 - Movie::get_year();
	return 0;
}