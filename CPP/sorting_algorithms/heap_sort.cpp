#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void printArray(int array[], int n)
{
    int i;
    std::cout << "Array: ";
    for (i = 0; i < n; i++)
    {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;
}

void heapify(int array[], int size, int root)
{
    int largest = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        swap(array[largest], array[root]);

        heapify(array, size, largest);
    }
}

void heapSort(int array[], int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);

        heapify(array, i, 0);
    }
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 34, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    heapSort(array, n);
    std::cout << "Sorted array: ";
    printArray(array, n);
    return 0;
}