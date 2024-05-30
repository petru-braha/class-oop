//professor's experience
#include <iostream>
#include "calls to all demonstrations.h"
int which_task;

void print_functions()
{
	std::cout << "the list of functions: \n";
	switch (which_task)
	{
	case 1:
		std::cout << "index '0': H1_sum\n";
		std::cout << "index '1': H1_lenght_sort\n";
		std::cout << "index '2': H1_mainProblem\n";
		std::cout << "index '3': H1_extra_main\n";
		break;
	case 2:
		std::cout << "index '4': H2_numberList_main\n";
		std::cout << "index '5': H2_student_main\n";
		std::cout << "index '6': H2_movie_main\n";
		break;
	case 3:
		std::cout << "index '7': H3_mathematics_main\n";
		std::cout << "index '8': H3_canva_main\n";
		std::cout << "index '50':H3_canva_extra_main\n";

		break;
	case 4:
		std::cout << "index '9': H4_sort_main\n";
		break;
	case 5:
		std::cout << "index '10': H5_number_main\n";
		std::cout << "index '51': H5_complex_extra_main\n";
		break;
	case 6:
		std::cout << "index '11': H6_cars_main\n";
		std::cout << "index '53': H6_extra_main\n";
		break;
	case 7:
		std::cout << "index '12': H7_literals_main\n";
		std::cout << "index '13': H7_tree_main\n";
		std::cout << "index '52': H7_vector_extra_main\n";
		break;
	case 8:
		std::cout << "index '14': H8_string_main\n";
		break;
	case 9:
		std::cout << "index '15': H9_map_main\n";
		break;
	case 10:
		std::cout << "index '16': H10_array_main\n";
		break;
	default:
		std::cout << "there is not homework indexed like that.\n";
		break;
	}
	std::cout << '\n';
}

void caller()
{
	switch (which_task)
	{
	case 0:  H1_extra_main(); break;
	case 1:  H1_lenght_sort(); break;
	case 2:  H1_mainProblem(); break;
	case 3:  H1_sum(); break;
	case 4:  H2_movie_main(); break;
	case 5:  H2_numberList_main(); break;
	case 6:  H2_student_main(); break;
	case 7:  H3_canva_main(); break;
	case 8:  H3_mathematics_main(); break;
	case 9:  H4_sort_main(); break;
	case 10: H5_number_main(); break;
	case 11: H6_cars_main(); break;
	case 12: H7_literals_main(); break;
	case 13: H7_tree_main(); break;
	case 14: H8_string_main(); break;
	case 15: H9_map_main(); break;
	case 16: H10_array_main(); break;
	
	case 50: H3_canva_extra_main(); break;
	case 51: H5_complex_extra_main(); break;
	case 52: H7_vector_extra_main(); break;
	case 53: H6_extra_main(); break;

	default:
		std::cout << "error: no function called.\n";
		break;
	}

	std::cout << "\n";
}

#include "Windows.h"
void call_homeworks()
{
	again:
	system("CLS");
	
	std::cout << "x-th homework, x== ";
	std::cin >> which_task;

	print_functions();
	std::cout << "to test: type the INDEX of a function name: ";
	std::cin >> which_task;
	caller();
	
	std::cout << "test anything else? (Y/N) ";
	char c = 0;
	std::cin >> c;
	if (c == 'Y')
		goto again;
}