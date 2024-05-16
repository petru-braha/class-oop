#include <iostream>
#include "ex 1/H3_Math.h"
void H3_mathematics_main()
{
    Math computation;
    int x, y, z;
    double a, b, c;
    
    std::cout << "insert 3 int values, then 3 float values: ";
    std::cin >> x >> y >> z >> a >> b >> c;

    std::cout << "add functions: ";
    std::cout << computation.Add(x, y) << ' ' 
              << computation.Add(x, y, z) << ' '
              << computation.Add(a, b) << ' '
              << computation.Add(a, b, c) << '\n';
    
    std::cout << "mul functions: ";
    std::cout << computation.Mul(x, y) << ' ' 
              << computation.Mul(x, y, z)<< ' ' 
              << computation.Mul(a, b) << ' ' 
              << computation.Mul(a, b, c) << '\n';

    std::cout << "variadic method: " << computation.Add(4, 1, 2, 3, 4) << '\n';
    
    const char first = 'a', second = 'b';
    std::cout << "const char function: " << computation.Add(first, second);
}

#include "ex 2/H3_canva.h"
#include <conio.h> //for getch
void H3_canva_main()
{
    Canvas window;
    window.Clear();

    window.DrawCircle(10, 10, 10, '.');
    window.FillCircle(10, 10, 10, '-');
    window.Print();
    window.Clear();
    std::cout << "press enter to continue";
    _getch();

    window.DrawRect(5, 5, 25, 25, '.');
    window.FillRect(5, 5, 25, 25, '-');
    window.Print();
    window.Clear();
    std::cout << "press enter to continue";
    _getch();

    window.SetPoint(10, 5, '*');
    window.SetPoint(40, 5, '*');
    window.DrawLine(15, 0, 40, 10, '-');
    window.Print();
    window.Clear();
    std::cout << "press enter to finish the program";
    _getch();
}