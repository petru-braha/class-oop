#include <stdio.h>
#include <cstdio>

template <class banana>
size_t partition(banana arr[], size_t index_start, size_t index_end)
{
    size_t pivot = arr[index_start];

    int count = 0;
    for (int i = index_start + 1; i <= index_end; i++)
        if (arr[i] <= pivot)
            count++;

    size_t pivot_index = index_start + count;
    swap(arr[pivot_index], arr[index_start]);

    size_t i = index_start, j = index_end;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pivot_index && j > pivot_index)
            swap(arr[i++], arr[j--]);
    }

    return pivot_index;
}

template <class banana>
void quick_sort(banana arr[], size_t index_start, size_t index_end)
{
    if (index_start >= index_end)
        return;
    size_t index_separator = partition(arr, index_start, index_end);

    quick_sort(arr, index_start, index_separator - 1);
    quick_sort(arr, index_separator + 1, index_end);
}

//Daniel tests my code
//testing of his code will be done in an separated project == subfolder of HH11