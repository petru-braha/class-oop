#pragma once
#include <stdio.h>

template <class T>
class Vector
{
	#define maximum 1000
	T values[maximum];
	size_t size;

	size_t partition(T val[], size_t index1, size_t index2)
	{
		T pivot = val[index1];

		int count = 0;
		for (size_t i = index1 + 1; i <= index2; i++)
			if (val[i] <= pivot)
				count++;
		
		size_t index_pivot = index1 + count;
		T temp = val[index1];
		val[index1] = val[index_pivot];
		val[index_pivot] = temp;

		size_t index_element_left = index1 + 1, index_element_right = index2;
		while (index_element_left < index_element_right)
		{
			while (val[index_element_left] <= pivot)
				index_element_left++;
			while (val[index_element_right] > pivot)
				index_element_right--;

			if (index_element_left < index_element_right)
			{
				T temp = val[index_element_left];
				val[index_element_left] = val[index_element_right];
				val[index_element_right = temp];
				index_element_left++;
				index_element_right--;
			}
		}

		return index_pivot;	
	}

	void quick_sort(T val[], size_t start, size_t end)
	{
		if (start >= end)
			return;
		size_t p = partition(val, start, end);
		quick_sort(val, start, p - 1);
		quick_sort(val, p + 1, end);
	}
public:
	Vector()
	{
		for (size_t i = 0; i < maximum; i++)
			values[i] = NULL;
		size = 0;
	}

	Vector(Vector& u)
	{
		for (size_t i = 0; i < maximum; i++)
		{
			if (i < u.size || i == 0)
				values[i] = u[i];
			else
				values[i] = NULL;
		}

		size = u.size;
	}

	Vector(Vector&& u)
	{
		for (size_t i = 0; i < maximum; i++)
		{
			if (i < u.size)
				values[i] = u[i];
			else
				values[i] = NULL;
		}

		size = u.size;
	}

	T& operator[] (const size_t& index)
	{
		if (index >= 0 && index < size)
			return values[index];
		T n = NULL;
		return n;
	}

	void insert(const size_t& index, const T& element)
	{
		if (index < 0 || index > maximum)
			return;
		if (values[index] == NULL)
			size++;
		values[index] = element;
	}

	void remove(const size_t& index)
	{
		if (index < 0 || index > size)
			return;
		for (size_t i = index; i < size - 1; i++)
			values[i] = values[i + 1];
		values[--size] = NULL;
	}

	void sort(int (*comparison)(T, T))
	{
		bool sorted = false;
		while (sorted == false)
		{
			sorted = true;
			for(size_t i = 1; i < size; i++)
				if (comparison(values[i - 1], values[i]) > 0)
				{
					sorted = false;
					T temp = values[i - 1];
					values[i - 1] = values[i];
					values[i] = temp;
				}
		}
	}

	void sort()
	{
		quick_sort(values, 0, size - 1);
	}
	
	void print()
	{
		for (size_t i = 0; i < size; i++)
			printf("%d ", values[i]);
	}

	~Vector(){}
};	