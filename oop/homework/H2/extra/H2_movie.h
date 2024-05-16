#pragma once

class Movie
{
	char name[256] = { 0 };
	short release_year = 0;
	double imdb_score = 0;
	char minutes_lenght = 0;

public:
	void set_name(const char input[]);
	char* get_name();

	void set_year(short input);
	short get_year();

	void set_score(double input);
	double get_score();

	void set_length(char input);
	char get_length();

	int time_passed();
};