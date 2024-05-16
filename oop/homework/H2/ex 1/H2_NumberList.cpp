#include "H2_NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count < 10)
	{
		this->numbers[this->count++] = x;
		return 1;
	}
    std::cout << "error: the list is full.\n";
	return 0;
}

void NumberList::Sort()
{
    int n = this->count;
    for (int i = 1; i < n; i++) 
    {
        int key = this->numbers[i];
        int j = i - 1;

        while (j >= 0 && this->numbers[j] > key) 
        {
            this->numbers[j + 1] = this->numbers[j];
            j = j - 1;
        }
        this->numbers[j + 1] = key;
    }
}

void NumberList::Print()
{
    if (this->count)
    {
        std::cout << "number list: ";
        for (int i = 0; i < this->count; i++)
            std::cout << this->numbers[i] << ' ';
        std::cout << '\n';
    }
    else
        std::cout << "error: there are no values.\n";
}