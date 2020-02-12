#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        const int n = nums.size();
        int sum = 0;
        for (auto const &i : nums)
        {
            sum += i;
        }

        if (sum % 2)
        {
            return false;
        }

        int W = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(W + 1, 0));
        
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (nums[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][W];
    }
};