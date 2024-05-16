#include <iostream>
#include "ex 1/H4_sort.h"

void H4_sort_main()
{
    Sort list_fromRandom(5, 9, 25);
    list_fromRandom.Print();
    std::cout << list_fromRandom.GetElementsCount() << " " << list_fromRandom.GetElementFromIndex(1) << '\n';
    list_fromRandom.InsertSort();
    list_fromRandom.Print();
    std::cout << '\n';

    Sort default_list;
    default_list.Print();
    std::cout << default_list.GetElementsCount() << " " << default_list.GetElementFromIndex(2) << '\n';
    default_list.BubbleSort();
    default_list.Print();
    std::cout << '\n';

    int array[] = { 6, 3, 7, 2, 1 };
    Sort list_fromArray(array, 5);
    list_fromArray.Print();
    std::cout << list_fromArray.GetElementsCount() << " " << list_fromArray.GetElementFromIndex(3) << '\n';
    list_fromArray.QuickSort();
    list_fromArray.Print();
    std::cout << '\n';

    Sort variadic_list(5, 3, 5, 2, 56, 1);
    variadic_list.Print();
    std::cout << variadic_list.GetElementsCount() << " " << variadic_list.GetElementFromIndex(4) << '\n';
    variadic_list.QuickSort();
    variadic_list.Print();
    std::cout << '\n';

    Sort list_fromString("10,6,7,24,12,155");
    list_fromString.Print();
    std::cout << list_fromString.GetElementsCount() << " " << list_fromString.GetElementFromIndex(5) << '\n';
    list_fromString.BubbleSort();
    list_fromString.Print();
    std::cout << '\n';
}