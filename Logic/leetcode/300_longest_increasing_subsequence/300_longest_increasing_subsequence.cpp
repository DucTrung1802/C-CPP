#include <iostream>
#include <vector>

using namespace std;

/**
 * My own solution
 */

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // int maxi = 0;
        vector<int> t;
        t.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > t.back())
                t.push_back(nums[i]);
            else
            {
                auto it = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
                t[it] = nums[i];
            }
        }
        return t.size();
    }
};

int main()
{
    Solution solution;
    vector<int> vector1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << solution.lengthOfLIS(vector1) << std::endl;
    return 0;
}