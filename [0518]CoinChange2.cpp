#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;

        int ssize = coins.size();
        vector<vector<int>> dp(ssize + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= ssize; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= amount; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= ssize; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (j >= coins[i - 1])
                    for (int k = 1; k <= j / coins[i - 1]; k++)
                        dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
            }
        }

        return dp[ssize][amount];
    }
};