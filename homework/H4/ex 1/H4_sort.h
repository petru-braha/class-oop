class Sort
{
    int list[300], k;

public:
    Sort(int n, int minimum, int maximum);
    Sort();
    Sort(int v[100], int n);
    Sort(int n, ...);
    Sort(const char s[100]);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false); 
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};