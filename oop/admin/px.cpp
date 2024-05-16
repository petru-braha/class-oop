//professor's experience
#include <iostream>
#include "calls to all demonstrations.h"
char which_task[300];

void print_functions(int index)
{
	std::cout << "the list of functions: \n";
	switch (index)
	{
	case 1:
		std::cout << "H1_sum\n";
		std::cout << "H1_lenght_sort\n";
		std::cout << "H1_mainProblem\n";
		std::cout << "H1_extra_main\n";
		break;
	case 2:
		std::cout << "H2_numberList_main\n";
		std::cout << "H2_student_main\n";
		std::cout << "H2_movie_main";
		break;
	case 3:
		std::cout << "H3_mathematics_main\n";
		std::cout << "H3_canva_main\n";
		break;
	case 4:
		std::cout << "H4_sort_main\n";
		break;
	case 5:
		std::cout << "H5_number_main\n";
		break;
	case 6:
		std::cout << "H6_cars_main\n";
		break;
	case 7:
		std::cout << "H7_literals_main\n";
		std::cout << "H7_tree_main\n";
		break;
	case 8:
		std::cout << "H8_string_main\n";
		break;
	case 9:
		std::cout << "H9_map_main\n";
		break;
	case 10:
		break;
	default:
		break;
	}
	std::cout << '\n';
}

#include <cstring>
void caller()
{
	if (strcmp(which_task, "H1_extra_main") == 0)
		H1_extra_main();
	if (strcmp(which_task, "H1_lenght_sort") == 0)
		H1_lenght_sort();
	if (strcmp(which_task, "H1_mainProblem") == 0)
		H1_mainProblem();
	if (strcmp(which_task, "H1_sum") == 0)
		H1_sum();
	if (strcmp(which_task, "H2_movie_main") == 0)
		H2_movie_main();
	if (strcmp(which_task, "H2_numberList_main") == 0)
		H2_numberList_main();
	if (strcmp(which_task, "H2_student_main") == 0)
		H2_student_main();
	if (strcmp(which_task, "H3_canva_main") == 0)
		H3_canva_main();
	if (strcmp(which_task, "H3_mathematics_main") == 0)
		H3_mathematics_main();
	if (strcmp(which_task, "H4_sort_main") == 0)
		H4_sort_main();
	if (strcmp(which_task, "H5_number_main") == 0)
		H5_number_main();
	if (strcmp(which_task, "H6_cars_main") == 0)
		H6_cars_main();
	if (strcmp(which_task, "H7_literals_main") == 0)
		H7_literals_main();
	if (strcmp(which_task, "H7_tree_main") == 0)
		H7_tree_main();
	if(strcmp(which_task, "H8_string_main") == 0)
		H8_string_main();
	if (strcmp(which_task, "H9_main") == 0)
		//H9_map_main();

	std::cout << "\n";
}

#include "Windows.h"
void call_homeworks()
{
	again:
	system("CLS");
	//which laboratory
	std::cout << "x-th homework, x== ";
	std::cin >> which_task;

	print_functions(which_task[0] - '0');
	std::cout << "to test: type the function's name: ";
	std::cin >> which_task;
	caller();
	
	std::cout << "test anything else? (Y/N) ";
	std::cin >> which_task;
	if (which_task[0] == 'Y')
		goto again;
}