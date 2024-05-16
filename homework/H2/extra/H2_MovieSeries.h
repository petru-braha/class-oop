#include "H2_movie.h"

class MovieSeries //like a list
{
	Movie* p;
public:
	void initt();
	void addd(Movie* pointer_movie);
	void sortt();
	void printt();
};