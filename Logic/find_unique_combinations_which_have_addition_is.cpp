/**
 * Give an integer array.
 * Find combinations of 3 numbers those have addition is 8 (random value).
 * Extend: Combinations of 4, 5, 6... numbers.
 */

#include <iostream>
#include <vector>

#define TARGET 10
#define COMBINATION 3

void FindUniqueCombinationsHaveSum(std::vector<int> array, std::vector<int> &current, int target, int start)
{
    if (current.size() == COMBINATION && target == 0)
    {
        for (int i = 0; i < current.size() - 1; i++)
        {
            std::cout << current[i] << " + ";
        }
        std::cout << current[current.size() - 1] << " = " << TARGET << std::endl;
    }

    if (current.size() < COMBINATION)
    {
        std::vector<int> tempVector = array;

        for (int i = start; i < array.size(); i++)
        {
            array = tempVector;
            int element = array[i];
            current.push_back(element);
            array.erase(array.begin() + i);
            FindUniqueCombinationsHaveSum(array, current, target - element, i);
            current.pop_back();
        }
    }
}

int main()
{
    std::vector<int> array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> current;

    FindUniqueCombinationsHaveSum(array, current, TARGET, 0);

    return 0;
}