#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Not my solution
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        if (all_of(nums.begin(), nums.end(), [&](const int i)
                   { return i == 0; }))
        {
            return {{0, 0, 0}};
        }
        auto min = nums[0];
        auto max = nums[0];
        for (auto &i : nums)
        {
            min = std::min(i, min);
            max = std::max(i, max);
        }
        size_t h = max - min + 1;
        vector<int> store(h, 0);
        for (auto &i : nums)
        {
            size_t j = i - min;
            if (store[j] < 3)
            {
                ++store[j];
            }
        }

        int unique = 0;
        for (int i = 0; i < h; i++)
        {
            if (store[i] != 0)
            {
                nums[unique++] = i + min;
            }
        }

        vector<vector<int>> ans;
        auto l = nums.begin();
        auto r = next(nums.begin(), unique - 1);

        if ((*l <= 0 && *r <= 0) || (*l >= 0 && *r >= 0))
        {
            return {};
        }

        while (*l <= 0)
        {
            while (*r >= 0)
            {
                int need = -(*l + *r);
                int j = need - min;

                if (need < *l)
                {
                    r--;
                    continue;
                }
                if (need > *r)
                {
                    r--;
                    continue;
                }

                if (((*l == need || *r == need) && store[j] == 1) ||
                    ((*l == need && *r == need) && store[j] == 2))
                {
                    r--;
                    continue;
                }
                if (store[j] != 0)
                {
                    ans.push_back({*l, need, *r});
                }
                r--;
            }
            l++;
            r = next(nums.begin(), unique - 1);
        }
        return ans;
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