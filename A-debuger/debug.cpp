#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ssize = prices.size();

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

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}