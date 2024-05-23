#pragma once
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <algorithm>

template <typename T>
class StaticVector {
    unsigned size;
    T* elements;

    void mergeSort(T* arr, unsigned left, unsigned right);
    void merge(T* arr, unsigned left, unsigned mid, unsigned right);
public:
    StaticVector(std::initializer_list<T> list);
    ~StaticVector();

    T& operator[](unsigned index);

    void mergeSort();
    unsigned get_size() { return size; }
};

template <typename T>
StaticVector<T>::StaticVector(std::initializer_list<T> list) : size(list.size()), elements(new T[size]) {
    unsigned it = 0;
    for (const auto& elem : list)
        new (&elements[it++]) T(elem);
}

template <typename T>
StaticVector<T>::~StaticVector() {
    delete[] elements;
}

template <typename T>
T& StaticVector<T>::operator[](unsigned index) {
    if (index >= size)
        throw std::out_of_range("Index_out_of_bounds");
    return elements[index];
}

template <typename T>
void StaticVector<T>::mergeSort() {
    mergeSort(elements, 1, size - 1);
}

template <typename T>
void StaticVector<T>::mergeSort(T* arr, unsigned left, unsigned right) {
    if (left >= right)
        return;
    unsigned mid = left + (right - left);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void StaticVector<T>::merge(T* arr, unsigned left, unsigned mid, unsigned right) {

        unsigned n1 = mid - left + 1;
        unsigned n2 = right - mid;

        T* L = new T[n1];
        T* R = new T[n2];

        std::copy(arr + left, arr + left + n1, L);
        std::copy(arr + mid + 1, arr + mid + 1 + n2, R);

        unsigned i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            k++;
        }

        delete L;
        delete[] R;
}