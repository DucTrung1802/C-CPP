#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * My own solution
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        unordered_map<int, int> umap;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % ((numRows - 1) * 2) == 0)
            {
                umap[0]++;
            }
            else if (i % (numRows - 1) == 0)
            {
                umap[(numRows - 1)]++;
            }
            else if (i % ((numRows - 1) * 2) > (numRows - 1))
            {
                umap[(i - (numRows - 1)) % (numRows - 1)]++;
            }
            else
            {
                umap[(i % (numRows - 1))]++;
            }
        }

        string result;
        int index = 0;
        int count = 0;
        while (index < numRows)
        {
            count = umap[index];
            while (count > 0)
            {
                result.push_back(s[(umap[index] - count) * (numRows - 1) * 2 + index]);
                count--;
            }
            index++;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string result = solution.convert("ABCDEFG", 3);
    cout << result << endl;
    return 0;
}
