#include <iostream>
#include <vector>

using namespace std;

/**
 * MY OWN SOLUTION !
 */

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int length_1 = nums1.size();
        int length_2 = nums2.size();
        int total_length = length_1 + length_2;
        vector<int> merged_nums(total_length, 0);
        int index_1 = 0;
        int index_2 = 0;
        for (int i = 0; i < (total_length); i++)
        {
            if (index_1 < length_1 && index_2 < length_2)
            {
                if (nums1[index_1] < nums2[index_2])
                {
                    merged_nums[i] = nums1[index_1];
                    index_1++;
                }
                else
                {
                    merged_nums[i] = nums2[index_2];
                    index_2++;
                }
            }
            else if (index_1 < length_1)
            {
                merged_nums[i] = nums1[index_1];
                index_1++;
            }
            else if (index_2 < length_2)
            {
                merged_nums[i] = nums2[index_2];
                index_2++;
            }
        }

        if (total_length % 2)
        {
            return (double)(merged_nums[total_length / 2]);
        }
        else
        {
            return ((double)(merged_nums[total_length / 2 - 1] + merged_nums[total_length / 2]) / 2);
        }
    }
};

int main()
{
    Solution solution;
    vector<int> vector_1 = {1, 2};
    vector<int> vector_2 = {3, 4};
    double result = solution.findMedianSortedArrays(vector_1, vector_2);
    cout << result << endl;
    return 0;
}
