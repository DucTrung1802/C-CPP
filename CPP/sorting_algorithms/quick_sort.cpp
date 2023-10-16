#include <iostream>
#include <vector>

template <typename T>

void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void printArray(std::vector<int> array)
{
    int i;
    std::cout << "Array: ";
    for (i = 0; i < array.size(); i++)
    {
        std::cout << " " << array[i];
    }
    std::cout << std::endl;
}

int partition(std::vector<int> &array, int start, int end)
{
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[j], array[i]);
        }
    }

    i++;
    swap(array[i], array[end]);

    return i;
}

void quickSort(std::vector<int> &array, int start, int end)
{
    if (end <= start)
    {
        return;
    }

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}

int main()
{
    std::vector<int> array = {64, 34, 25, 12, 22, 34, 11, 90};
    quickSort(array, 0, array.size() - 1);
    std::cout << "Sorted array: ";
    printArray(array);
    return 0;
}