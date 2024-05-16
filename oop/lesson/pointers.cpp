#include <iostream>
#include <stdio.h>

void pointers()
{
    int arr[] = { 3, 5, 6, 7, 9 }, * p = nullptr;

    //pointers VS references:
    p = arr;
    std::cout << "remember: " << *p;
    (*p) = 5;
    std::cout << ' ' << *p << '\n';
    /*
    references:
    +: forced to initalise, don't have to check NULL
    -: can not change values
    -: NO cast

    *p = 10 explained: "*" = the value where p points at
    **p = 1 explained: "*" = the value where *p points at
    */

    //pointer to first element
    p = arr + 1;
    p = (int*)arr;
    printf("%d\n", *p);

    //changing the array with pointers
    *p = 10;
    p[1] = 11;
    *(p + 1) = 11;
    std::cout << arr[0] << ' ' << arr[1];
}
void advanced_pointers()
{
    char mem[11] = { 1, 1, 2, -1, 0, 2, -2, 3, 97, 48, 0 };
    short f = ((short*)(mem + 3))[0];
    int q = *(int*)(mem + 1);
    char* s = ((char*)(mem + 8));
    short r = ((short*)mem)[4];
    printf("f= %d | q=%08X | s=%s | r=%c%c\n", f, q, s, r / 256, r % 256);
}

//pointers to functions
typedef int (*functions)(int, int);
int S(int a, int b) { return a + b; }
int D(int a, int b) { return a - b; }
int M(int a, int b) { return a * b; }
int DV(int a, int b) { return a / b; }
void point_functions()
{
    functions arr_pF[4] = { &S, &D, &M, &DV };
    for (int i = 0; i < 4; i++)
        std::cout << arr_pF[i](6, 3) << ' ';
}

//change the value of m outside of the function
int fyp(int* m_address)
{
    static int m = 100;
    *m_address = (int)&m;
    return m++;
}

void change_value_static()
{
    int static_address = 0;
    int a = fyp(&static_address);
    *(int*)static_address = 1000;
    int b = fyp(&static_address);
    std::cout << a << b;
}

void const_point()
{
    //p points to a constant value => value modification == false
    const int* p = 0;
    int const* p2 = 0;//the same
    p++;

    int x = 60;
    int* const pointer = &x; //const pointer => value modification == true
    *p++;

    int** ptp = 0;
    int* const* ptop = 0; // it is a non-const pointer to a const pointer to a non-const value
}