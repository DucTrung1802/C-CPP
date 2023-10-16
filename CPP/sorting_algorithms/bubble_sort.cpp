#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
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
    bubbleSort(arr, size);
    std::cout << "Sorted array: ";
    printArray(arr, size);
    return 0;
}