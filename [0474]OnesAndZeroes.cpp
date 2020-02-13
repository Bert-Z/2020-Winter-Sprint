#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto str : strs)
        {
            int ones = 0, zeros = 0;
            getOnesZeros(str, zeros, ones);

            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }

        return dp[m][n];
    }

private:
    void getOnesZeros(string &str, int &zeros, int &ones)
    {
        for (auto c : str)
        {
            if (c == '1')
                ones++;

            if (c == '0')
                zeros++;
        }
    }
};