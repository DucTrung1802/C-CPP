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
        if (s.empty())
        {
            return "";
        }

        if (s.size() == 1)
        {
            return s;
        }

        int pivot = 0;
        int max_length = 1;
        int length = s.size();
        bool fail = false;
        int left, right, i, j;

        for (left = 0; left < length; left++)
        {
            if (length - left <= max_length)
            {
                break;
            }

            for (right = length - 1; right > left; right--)
            {
                int sub_length = right - left + 1;
                fail = false;

                int half = left + sub_length / 2;
                for (i = left, j = 0; i < half; i++, j++)
                {
                    if (s[i] != s[right - j])
                    {
                        fail = true;
                        break;
                    }
                }

                if (!fail && sub_length > max_length)
                {
                    pivot = left;
                    max_length = sub_length;
                    break;
                }
            }
        }

        return s.substr(pivot, max_length);
    }
};

int main()
{
    Solution solution;
    // string string_1 = "xzyabcdcbakl";
    // string string_1 = "aacabdkacaa";
    // string string_1 = "ababa";
    string string_1 = "babadada";
    string result = solution.longestPalindrome(string_1);
    cout << result << endl;
    return 0;
}
