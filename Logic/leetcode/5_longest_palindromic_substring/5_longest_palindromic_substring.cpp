#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Not my solution !
 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = s.size();
        int pivot = 0;
        int max_length = 1;
        int left, right;
        for (int i = 0; i < length;)
        {
            left = i;
            right = i;

            while (right < length - 1 && s[right] == s[right + 1])
            {
                right++;
            }

            i = right + 1;

            while (left > 0 && right < length - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }

            if (right - left + 1 > max_length)
            {
                pivot = left;
                max_length = right - left + 1;
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
    string string_1 = "aaaaabcdcba";
    string result = solution.longestPalindrome(string_1);
    cout << result << endl;
    return 0;
}
