#include <iostream>

int g(int x)
{
    std::cout << "g";
    return 0;
}

int f()
{
    std::cout << "f";
    return 0;
}

int ff()
{
    std::cout << "ff";
    return 5;
}

int sum(int x, int y) { return x + y; }

typedef int (*functions)(int, int);
int ad_ptr1()
{
    int a = (*f)();
    a = (*ff)();
    a = (*sum)(1, 2); // in the equality is also the calling
    std::cout << "\n";

    void* ptr = &sum;
    std::cout << "first function's result: "    << ((int (*)(int, int))ptr)(1, 2) << '\n';
    ptr = &g;
    std::cout << "second function's result: "   << ((int (*)(int))ptr)(1) << '\n';
    ptr = &ff;
    std::cout << "third function's result: "    << ((int (*)())ptr)() << '\n';
    return 0;
}

//----------------------------------------------------------------------------------------------------------------
#include <functional>

bool is_prime(int x)
{
    return x % 2;
}

struct x
{
    void* ptr; // std::function<bool(int)> ptr;
    x(bool (*f)(int) )
    {
        ptr = (void*)f;
    }

    void execute()
    {
        if (((bool (*)(int))ptr)(1))
            std::cout << "ma fut";
    }
};

int ad_ptr2()
{
    x cetate(is_prime);
    cetate.execute();
    return 0;
}