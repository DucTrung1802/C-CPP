#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * MY OWN SOLUTION !
 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = s.size();

        if (length == 1)
        {
            return s;
        }

        int index = 0;
        int longest_length = 0;
        int reverse_index;
        string temp;
        for (int i = 0; i < length; i++)
        {
            reverse_index = s.find_last_of(s[i]);
            if (i != reverse_index)
            {
                temp = s;
                reverse(s.begin() + i, s.begin() + reverse_index + 1);
                if (temp == s)
                {
                    index = i;
                    longest_length = reverse_index - i + 1;
                    i = reverse_index + 1;
                }
            }
        }

        if (longest_length)
        {
            return s.substr(index, longest_length);
        }

        return "";
    }
};

int main()
{
    Solution solution;
    string string_1 = "xzyabbcbbakl";
    string result = solution.longestPalindrome(string_1);
    cout << result << endl;
    return 0;
}
