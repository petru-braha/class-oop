#include "ex 1\H2_NumberList.h"
void H2_numberList_main()
{
	NumberList A;
	A.Print();
	A.Init(); A.Print();

	A.Add(2); A.Print();

	A.Add(1); A.Add(5); A.Add(4); A.Add(3); A.Print();
	
	A.Sort(); A.Print();

	A.Add(9);
	A.Add(9);
	A.Add(9);
	A.Add(9);
	A.Add(9);
	std::cout<<A.Add(9)<<'\n'; //error
	A.Print();	
}

#include "ex 2\H2_studentFct.h"
void H2_student_main()
{
	student intern, bachelor;  //the names of the students must end with '.'
	intern.setName();
	intern.setMTH();
	intern.setENG();
	intern.setHST();
	std::cout << intern.getName() << "'s average: " << intern.average_grade() << "\n";
	
	//test unitialised values
	std::cout << bachelor.getName();

	//test for global functions
	bachelor.setName();
	bachelor.setENG();
	bachelor.setMTH();
	bachelor.setHST();
	std::cout << "comparison: name, eng, hst, math, avg:\n";
	std::cout << compare_name(intern, bachelor) << compare_ENG(intern, bachelor) << compare_HST(intern, bachelor) << compare_MTH(intern, bachelor) << compare_AVG(intern, bachelor);
}

#include "extra/H2_movies_comparison.h"
#include "extra/H2_MovieSeries.h"
void H2_movie_main()
{
	//status: name comparison not working + movie series 
	Movie ep5;
	ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
	ep5.set_score(8.7);
	ep5.set_year(1980);
	ep5.set_length(124);

	Movie ep4;
	ep4.set_name("Star Wars: Episode IV - A New Hope");
	ep4.set_score(8.6);
	ep4.set_year(1977);
	ep4.set_length(121);

	Movie ep6;
	ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
	ep6.set_score(8.3);
	ep6.set_year(1983);
	ep6.set_length(131);
	
	printf(
		R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
movie_compare_name(ep4, ep5),
movie_compare_year(ep4, ep5),
movie_compare_score(ep4, ep5),
movie_compare_length(ep4, ep5),
movie_compare_passed_years(ep4, ep5));
	/*
	MovieSeries series;
	series.init();
	series.add(&ep5);
	series.add(&ep4);
	series.add(&ep6);

	series.sort();
	series.print();*/
}