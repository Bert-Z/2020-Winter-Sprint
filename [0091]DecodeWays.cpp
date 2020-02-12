#include <bits/stdc++.h>

using namespace std;

// 关于递归公式，让我们先局部后整体。对于局部，我们遍历到一个元素的时候， 我们有两种方式来组成编码方式，第一种是这个元素本身（需要自身是[1,9]）, 第二种是它和前一个元素组成[10, 26]。 用伪代码来表示的话就是： dp[i] = 以自身去编码（一位） + 以前面的元素和自身去编码（两位） .这显然是完备的， 这样我们通过层层推导就可以得到结果。
// 因为位数不一样，所以转换公式的两个因子一定不存在重复的情况。

class Solution
{
public:
    int numDecodings(string s)
    {
        int ssize = s.size();

        if (ssize == 0)
            return 0;

        vector<int> dp(ssize + 1);

        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;

        for (int i = 2; i <= ssize; i++)
        {
            int one = stoi(s.substr(i - 1, 1));
            int two = stoi(s.substr(i - 2, 2));

            if (two >= 10 && two <= 26)
                dp[i] = dp[i - 2];

            if (one != 0)
                dp[i] += dp[i - 1];
        }

        return dp[ssize];
    }
};