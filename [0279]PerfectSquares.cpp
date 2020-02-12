#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// recursive + cache
// class Solution
// {
// public:
//     int numSquares(int n)
//     {

//         int i = 1, now = 1;
//         while (now <= n)
//         {
//             squares.insert(now);
//             i++;
//             now = i * i;
//         }

//         return helper(n);
//     }

// private:
//     set<int> squares;
//     unordered_map<int, int> cache;

//     inline int helper(int n)
//     {
//         if (squares.find(n) != squares.end())
//             return 1;

//         if (cache.find(n) != cache.end())
//             return cache[n];

//         set<int> alls;

//         for (auto it = squares.rbegin(); it != squares.rend(); it++)
//         {
//             if (*it > n)
//                 continue;

//             alls.insert(helper(n - *it) + 1);
//         }

//         int ret = *(alls.begin());
//         cache[n] = ret;

//         return ret;
//     }
// };

// dp
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT32_MAX);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }

        return dp[n];
    }
};