#include <iostream>
#include <vector>

using namespace std;

/**
 * Not my solution !
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int string_length = s.length();
        int max_length = 0;
        vector<int> char_index(128, -1);
        int left = 0;

        for (int right = 0; right < string_length; right++)
        {
            if (char_index[s[right]] >= left)
            {
                left = char_index[s[right]] + 1;
            }
            char_index[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

int main()
{
    string input_string = "qwertyuiopq";
    Solution solution;
    int result = solution.lengthOfLongestSubstring(input_string);
    std::cout << result << std::endl;
    return 0;
}
