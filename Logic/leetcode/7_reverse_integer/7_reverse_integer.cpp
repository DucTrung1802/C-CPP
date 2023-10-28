#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * My own solution
 */

class Solution
{
    string limit = "2147483647";

public:
    int reverse(int x)
    {
        if (x <= INT_MIN || x > INT_MAX || x == 0)
        {
            return 0;
        }

        string negative = "";
        string number;
        if (x < 0)
        {
            x *= -1;
            negative = "-";
        }
        number = to_string(x);

        std::reverse(number.begin(), number.end());

        if (number.size() >= limit.size() && number > limit)
        {
            return 0;
        }

        return stoi(negative + number);
    }
};

int main()
{
    Solution solution;
    int result = solution.reverse(-1234567899);
    std::cout << result << std::endl;
    return 0;
}