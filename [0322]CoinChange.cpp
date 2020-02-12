#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());

        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, INT32_MAX);

        for (int i = 1; i <= amount; i++)
        {
            for (int x : coins)
            {
                if (x > i)
                    break;

                if (x == i)
                    dp[i] = 1;

                if (dp[i - x] != INT32_MAX)
                    dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }

        if (dp[amount] == INT32_MAX)
            return -1;

        return dp[amount];
    }
};