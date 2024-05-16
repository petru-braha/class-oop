#include <iostream>
#include <cstdlib>  //for random
#include <stdarg.h>
#include <cstring>
#include "H4_sort.h"

Sort::Sort(int n, int minimum, int maximum)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        list[i] = minimum + (rand() % (maximum - minimum));
    k = n;
}

Sort::Sort()
{
    int second_list[] = {5, 4, 3, 2, 1};
    for (char i = 0; i < 5; i++)
        list[i] = second_list[i];
    k = 5;
}

Sort::Sort(int v[100], int n)
{
    for (int i = 0; i < n; i++)
        list[i] = v[i];
    k = n;
}

Sort::Sort(int n, ...)
{
    va_list args;
    va_start(args, n);

    k = n;

    int i = 0;
    while (n)
    {
        list[i] = va_arg(args, int);
        i++;
        n--;
    }
    va_end(args);
}

Sort::Sort(const char s[100])
{
    k = 0;
    int i = 0;
    
    int last_index = strlen(s), current_index = 0;

    while (i < last_index)
    {
        if (s[i] != ',')
            current_index = current_index * 10 + (s[i] - '0');
        else
        {
            list[k++] = current_index;
            current_index = 0;
        }
        i++;
    }
    list[k++] = current_index;
}

void Sort::InsertSort(bool ascendent)
{
    int key = 0;
    for (int i = 1; i < k; i++)
    {
        key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
    ascendent = true;
}

int partition(int list[], int asdl, int index)
{
    int x = list[index];
    int i = asdl - 1;

    for (int j = asdl; j <= index - 1; j++) {
        if (list[j] <= x)
        {
            i++;
            int aux = list[i];
            list[i] = list[j];
            list[j] = aux;
        }
    }
    int aux = list[++i];
    list[i] = list[index];
    list[index] = aux;
    return i;
}

void Sort::QuickSort(bool ascendent)
{
    int first_index = 0, last_index = k - 1;
    
    int stack[200] = { 0 };
    int top = -1;

    stack[++top] = first_index;
    stack[++top] = last_index;

    while (top >= 0)
    {
        last_index = stack[top--];
        first_index = stack[top--];

        int p = partition(list, first_index, last_index);

        if (p - 1 > first_index)
        {
            stack[++top] = first_index;
            stack[++top] = p - 1;
        }

        if (p + 1 < last_index)
        {
            stack[++top] = p + 1;
            stack[++top] = last_index;
        }
    }
    ascendent = true;
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (list[j] > list[j + 1])
            {
                int aux = list[j];
                list[j] = list[j + 1];
                list[j + 1] = aux;
            }
    ascendent = true;
}

void Sort::Print()
{
    for (int i = 0; i < k; i++)
        std::cout << list[i] << " ";
    std::cout << '\n';
}

int Sort::GetElementsCount()
{
    return k;
}

int Sort::GetElementFromIndex(int index)
{
    return list[index];
}