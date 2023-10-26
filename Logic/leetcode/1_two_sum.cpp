#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Not my solution !
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1};
    }
};

int main()
{
    Solution solution;
    vector<int> array = {96, 35, 74, 93, 100, 40, 67, 44, 41, 73};
    vector<int> result;
    result = solution.twoSum(array, 141);
    cout << result[0] << " " << result[1];
}