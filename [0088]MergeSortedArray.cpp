#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums3;
        int n1 = 0, n2 = 0;
        while (n1 < m && n2 < n)
        {
            if (nums1[n1] < nums2[n2])
            {
                nums3.push_back(nums1[n1]);
                n1++;
            }
            else
            {
                nums3.push_back(nums2[n2]);
                n2++;
            }
        }

        while (n1 < m)
        {
            nums3.push_back(nums1[n1]);
            n1++;
        }

        while (n2 < n)
        {
            nums3.push_back(nums2[n2]);
            n2++;
        }

        nums1.clear();
        nums1.assign(nums3.begin(), nums3.end());
    }
};