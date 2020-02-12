#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int ssize = s.size();

        vector<bool> dp(ssize + 1, false);

        dp[0] = true;

        for (int i = 1; i <= ssize; i++)
        {
            for (auto x : wordDict)
            {
                if (x.size() > i)
                    continue;

                if (dp[i - x.size()] && s.substr(i - x.size(), x.size()) == x)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[ssize];
    }
};