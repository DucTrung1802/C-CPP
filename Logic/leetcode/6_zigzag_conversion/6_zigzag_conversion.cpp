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
    string convert(string s, int numRows)
    {
        if (s.empty() || numRows <= 1 || numRows > s.size())
        {
            return s;
        }

        vector<string> list_string(numRows);

        int j = 0;
        bool going_down = true;
        for (int i = 0; i < s.size(); i++)
        {
            list_string[j].append(s.substr(i, 1));

            if (j == 0)
            {
                going_down = true;
            }
            else if (j == numRows - 1)
            {
                going_down = false;
            }

            if (going_down)
            {
                j++;
            }
            else
            {
                j--;
            }
        }

        for (int i = 1; i < numRows; i++)
        {
            list_string[0].append(list_string[i]);
        }

        return list_string[0];
    }
};

int main()
{
    Solution solution;
    string result = solution.convert("PAYPALISHIRING", 4);
    cout << result << endl;
    return 0;
}