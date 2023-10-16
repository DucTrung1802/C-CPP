#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1] && j >= 1)
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << " " << arr[i];
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 34, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    std::cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}