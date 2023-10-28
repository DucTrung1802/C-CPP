#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Not my solution
 */

class Solution
{
public:
    bool isPalindrome(int n)
    {
        int rev = 0;
        int origin = n;
        if (n < 0)
        {
            return 0;
        }
        if (n < 10)
        {
            return 1;
        }

        while (n > 0)
        {
            int rem = n % 10;
            if (rev > INT_MAX / 10)
            {
                return 0;
            }
            rev = rev * 10 + rem;
            n = n / 10;
        }
        return (rev == origin);
    }
};

int main()
{
    Solution solution;
    std::cout << solution.isPalindrome(121) << std::endl;
    return 0;
}