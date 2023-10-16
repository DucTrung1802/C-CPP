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

void merge(std::vector<int> left_array, std::vector<int> right_array, std::vector<int> &array)
{
    int left_array_size = array.size() / 2;
    int right_array_size = array.size() - left_array_size;
    int i = 0; // index for main array
    int l = 0; // index for left array
    int r = 0; // index for right array

    while (l < left_array_size && r < right_array_size)
    {
        if (left_array[l] < right_array[r])
        {
            array[i] = left_array[l];
            i++;
            l++;
        }
        else
        {
            array[i] = right_array[r];
            i++;
            r++;
        }
    }
    while (l < left_array_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }
    while (r < right_array_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}

void mergeSort(std::vector<int> &array)
{
    // No need to be divided anymore
    int size = array.size();
    if (size <= 1)
    {
        return;
    }

    int midde = size / 2;
    std::vector<int> left_array;
    std::vector<int> right_array;

    for (int i = 0; i < size; i++)
    {
        if (i < midde)
        {
            left_array.push_back(array[i]);
        }
        else
        {
            right_array.push_back(array[i]);
        }
    }

    mergeSort(left_array);
    mergeSort(right_array);
    merge(left_array, right_array, array);
}

int main()
{
    std::vector<int> array = {64, 34, 25, 12, 22, 34, 11, 90};
    mergeSort(array);
    std::cout << "Sorted array: ";
    printArray(array);
    return 0;
}