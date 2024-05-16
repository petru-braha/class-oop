#pragma once
#include <iostream>
class NumberList
{
    int numbers[10];
    int count;
public:
    NumberList() : count(0) { for (int i = 0; i < 10; i++) numbers[i] = 0; }
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
};