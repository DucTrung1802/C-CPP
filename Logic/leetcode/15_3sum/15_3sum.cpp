#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * My own solution
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> vect_list = {};
        int length = nums.size();

        for (int i = 0; i < length; i++)
        {
            int left = i + 1;
            int right = length - 1;
            int target = 0 - nums[i];

            if (i >= 1 && i == (i - 1))
            {
                continue;
            }

            while (left < right)
            {
                while (left >= 1 && nums[left] == nums[left - 1])
                {
                    left++;
                }

                while (right < length - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                }

                if (nums[left] + nums[right] == target)
                {
                    vect_list.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return vect_list;
    }
};

int main()
{
    Solution solution;
    vector<int> vect = {-1, -2, -3, 3, 5, 3, 3, 3};
    vector<vector<int>> result;
    result = solution.threeSum(vect);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << result[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}