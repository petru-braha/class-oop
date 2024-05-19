#pragma once
#include <iostream>
#include <algorithm>

struct Compare
{
    virtual int CompareElements(void* e1, void* e2) = 0;
    virtual ~Compare() {}
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
    int Size;

public:
    ArrayIterator(T** list, int size) : List(list), Size(size), Current(0) {}

    ArrayIterator& operator ++ ()
    {
        if (Current < Size) Current++;
        return *this;
    }

    ArrayIterator& operator -- () {
        if (Current > 0)
            --Current;
        return *this;
    }

    bool operator= (ArrayIterator<T>& other) {
        if (this != &other) {
            this->Current = other.Current;
            this->pArray = other.pArray;
        }
        return *this;
    }

    bool operator!=(ArrayIterator<T>& other)
    {
        return !(*this == other);
    }

    T* GetElement()
    {
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei
    int Size; // numarul de elemente din lista

public:
    Array() : List(nullptr), Capacity(0), Size(0) { } // Lista nu e alocata, Capacity si Size = 0

    ~Array()
    {
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }

    Array(int capacity) : List{ new T * [capacity] }, Capacity{ capacity }, Size{ 0 } {} // Lista e alocata cu 'capacity' elemente

    Array(const Array<T>& otherArray) // constructor de copiere
    {
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
        for (int i = 0; i < Size; i++)
            List[i] = new T(*(otherArray.List[i]));
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if (index < 0 || index >= Size)
            throw std::out_of_range("Index out of range");
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) //adauga element la final
    {
        if (Size == Capacity)
        {
            Capacity *= 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) // adauga element la indexul dat; daca e invalid, da exceptie
    {
        if (index < 0 || index > Size)
        {
            throw std::out_of_range("Index out of range");
        }

        if (Size == Capacity)
        {
            Capacity *= 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }

        for (int i = Size - 1; i >= index; i--) {
            List[i + 1] = List[i];
        }

        List[index] = new T(newElem);
        Size++;

        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index; daca e invalid arunca exceptie
    {
        if (index < 0 || index > Size)
        {
            throw std::out_of_range("Index out of range");
        }

        int otherSize = otherArray.Size;
        if (otherSize == 0) {
            return *this;
        }

        // face resize daca e necesar
        while (Size + otherSize > Capacity) {
            Capacity *= 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++)
            {
                newList[i] = List[i];
            }
            for (int i = Size; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
        }

        for (int i = Size - 1; i >= index; i--) {
            List[i + otherSize] = List[i];
        }

        for (int i = 0; i < otherSize; i++) {
            List[index + i] = new T(otherArray.List[i]);
        }

        Size += otherSize;

        return *this;
    }

    const Array<T>& Delete(int index) // sterge element de pe pozitia index; daca e invalid arunca exceptie
    {
        if (index < 0 || index >= Size) {
            throw std::out_of_range("Index out of range.");
        }

        delete List[index];

        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }

        Size--;
        List[Size] = nullptr;

        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray) {
            return true;
        }

        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;

        List = new T * [Capacity];

        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }

        return true;
    }

    void Sort()
    {
        std::sort(List, List + Size);
    }

    void Sort(int(*compare)(const T&, const T&)) //dupa functie de comparatie
    {
        std::sort(List, List + Size, compare);
    }

    void Sort(Compare* comparator) //dupa un obiect de comparatie
    {
        if (Size <= 1) {
            return;
        }

        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem)
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            else if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) //cu functie de comparare
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = compare(*List[mid], elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator) //cu un comparator
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int comp = comparator->CompareElements(List[mid], &elem);
            if (comp == 0)
                return mid;
            else if (comp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem)
                return i;
        }

        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))//cu o functie de comparatie
    {
        for (int i = 0; i < Size; i++)
        {
            if (compare(*List[i], elem) == 0)
                return i;
        }

        return -1;
    }

    int Find(const T& elem, Compare* comparator) //cu un comparator
    {
        for (int i = 0; i < Size; i++)
        {
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        }

        return -1;
    }

    int GetSize()
    {
        return Size;
    }

    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> it;
        it.Current = 0;
        return it;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> it;
        it.Current = Size;
        return it;
    }
};