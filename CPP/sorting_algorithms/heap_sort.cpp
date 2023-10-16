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

void heapify(int arr[], int size, int root)
{

    // Initialize largest as root
    int largest = root;

    // left = 2*i + 1
    int left = 2 * root + 1;

    // right = 2*i + 2
    int right = 2 * root + 2;

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    // so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root)
    {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{

    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // One by one extract an element
    // from heap
    for (int i = size - 1; i > 0; i--)
    {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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