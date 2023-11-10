#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * My own solution
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        int limit = 0;
        bool found = false;
        while (!found)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                int pos = strs[i].find(strs[0][limit], limit);
                if (pos != limit)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                break;
            }
            else
            {
                limit++;
            }
        }

        return strs[0].substr(0, limit);
    }
};

int main()
{
    Solution solution;
    vector<string> vect = {"c", "acc", "ccc"};
    std::cout << solution.longestCommonPrefix(vect) << std::endl;
    return 0;
}