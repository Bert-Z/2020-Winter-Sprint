#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;

        // vector<int> cnums;

        // for (int x : coins)
        //     for (int i = 0; i < amount / x; i++)
        //         cnums.push_back(x);

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

        for (auto x : dp)
        {
            for (auto y : x)
                cout << " " << y;

            cout << endl;
        }

        return dp[ssize][amount];
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

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
        int amount = stringToInteger(line);
        getline(cin, line);
        vector<int> coins = stringToIntegerVector(line);

        int ret = Solution().change(amount, coins);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}