#include <iostream>
#include <vector>

using namespace std;

/**
 * Not my solution
 */

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            maxWater = std::max(maxWater, h * w);

            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return maxWater;
    }
};

int main()
{
    Solution solution;
    vector<int> vect = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << solution.maxArea(vect) << std::endl;
    return 0;
}