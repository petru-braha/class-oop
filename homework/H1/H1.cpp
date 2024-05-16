#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//1. Recap simple C library functions
int conversion(char number[])
{
    int element = 0;
    short int nr_digits = 0;

    bool is_negative = 0;
    if (number[0] == '-')
    {
        nr_digits++;
        is_negative = 1;
    }
    while (number[nr_digits + 1])
        nr_digits++;

    int p = 1;
    while (nr_digits > 0)
    {
        element += (number[nr_digits] - '0') * p;
        p *= 10;
        nr_digits--;
    }
    if (is_negative)
        return element * -1;
    return element += (number[0] - '0') * p;
}
void H1_sum()
{
    int s = 0;
    FILE* input = fopen("Homework/H1/numbers.txt", "r");
    if (input == nullptr) { std::cout << "error at opening.\n"; return; }

    char number[300] = { 0 };

    while (fgets(number, 300, input))
    {
        if(number[strlen(number)-1]=='\n')
            number[strlen(number)-1] = 0;
        s += conversion(number);
    }

    printf("the sum of the numbers is %d .\n", s);
    fclose(input);
}

//2. Recap scanf/printf
struct words {
    char word[100];
    int nr_letters;
} word_list[100];
void print(int n)
{
    for (int i = n - 1; i >= 0; i--)
        std::cout << word_list[i].word << '\n';
}
char* lexigographic_great(char c1[], char c2[])//needs revision here
{
    if (strcmp(c1, c2) > 0)
        return c2;
    return c1;
}

void change(int x, int y)
{
    char temp[100];
    strcpy(temp, word_list[x].word);
    strcpy(word_list[x].word, word_list[y].word);
    strcpy(word_list[y].word, temp);

    std::swap(word_list[x].nr_letters, word_list[y].nr_letters);
}

void heapify(words arr[], int index_last, int index)
{
    int left_child = 2 * index + 1, right_child = 2 * index + 2, index_largest = index;
    
    if (left_child < index_last && arr[left_child].nr_letters > arr[index].nr_letters)
        index_largest = left_child;

    if (right_child<index_last && arr[right_child].nr_letters > arr[index_largest].nr_letters)
        index_largest = right_child;

    if (index != index_largest)
    {
        change(index, index_largest);
        heapify(arr, index_last, index_largest);
    }
}

void H1_lenght_sort()
{
    char sentence[500] = { 0 }, *pointer;
    int lg_max = 0;

    std::cin.getline(sentence, 500);
    pointer = strtok(sentence, " ");

    //create the array
    short int index_word = 0;
    while (pointer)
    {
        strcpy(word_list[index_word].word, pointer);
        word_list[index_word++].nr_letters = (int)strlen(pointer);
        pointer = strtok(NULL, " ");
    }

    //heapsort
    for (int i = index_word / 2 - 1; i >= 0; i--)
        heapify(word_list, index_word, i);
    for (int i = index_word - 1; i >= 0; i--)
    {
        change(0, i);
        heapify(word_list, i, 0);
    }
    print(index_word);
}


//3. Some C and C++ problem
bool isPrime(int n)     //with the assumption that n is natural
{
    for (int tr = 2; tr < n / 2; tr++)
        if (n % tr == 0)
            return false;
    //special cases
    if (n == 0 || n == 1)
        return false;
    return true;
}
void H1_mainProblem()   //adapted such that could be called by the main from "OOP.cpp"
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
}


//4. Lab 1 Extra Find and solve all the mistakes in the following code. See as well the H1_lab_extra
#include "H1_lab_extra.h"
int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

void H1_extra_main()
{
    char input[] = "---***++++++///---+++/+-**---";
    func Operatori[4] = { &Sum, &Dif, &Mul, &Div };
    int Svalue = 0, idx = 0;
    Content x;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
        case '*':
            idx = 2;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case '+':
            idx = 0;
            x.p1 = 6;
            x.p2 = 5;
            break;
        case '-':
            idx = 1;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case '/':
            idx = 3;
            x.p1 = 92;
            x.p2 = 4;
            break;
        default:
            break;
        }

        //337
        Svalue += Operatori[idx](x.p1, x.p2); 
    }
    std::cout << Svalue;
}