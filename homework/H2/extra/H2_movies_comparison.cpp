#include "H2_movies_comparison.h"
#include <cstring>

short movie_compare_name(Movie one, Movie two)
{//REVISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	short value = 0; // strcmp(one.get_name(), two.get_name);
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}

short movie_compare_year(Movie one, Movie two)
{
	short value = one.get_year() - two.get_year();
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}

short movie_compare_score(Movie one, Movie two)
{
	double value = one.get_score() - two.get_score();
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}

short movie_compare_length(Movie one, Movie two)
{
	char value = one.get_year() - two.get_year();
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}

short movie_compare_passed_years(Movie one, Movie two)
{
	int value = one.get_year() - two.get_year();
	if (value > 0)
		return 1;
	if (value < 0)
		return -1;
	return 0;
}