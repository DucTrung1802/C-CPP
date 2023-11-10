#include <iostream>
#include <string>

using namespace std;

/**
 * My own solution
 */

class Solution
{
    int dict_size = 13;
public:
    // 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1

    int romanToInt(string s)
    {
        string dict[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int res = 0;
        int limit = 0;

        for (int i = 0; i < dict_size; i++)
        {
            while (s.find(dict[i], limit) == limit)
            {
                res += index[i];
                limit += dict[i].size();
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.romanToInt("MCMXCIV") << std::endl;
    return 0;
}