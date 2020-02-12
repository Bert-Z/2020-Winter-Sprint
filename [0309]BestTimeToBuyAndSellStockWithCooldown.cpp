#include <bits/stdc++.h>

using namespace std;

//   multiple states
//   buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
//   sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ssize = prices.size();

        if (ssize <= 1)
            return 0;

        vector<int> buy(ssize, 0);
        vector<int> sell(ssize, 0);

        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(0, prices[1] - prices[0]);

        for (int i = 2; i < ssize; i++)
        {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return max(buy[ssize - 1], sell[ssize - 1]);
    }
};