#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {

        int ret = 0;
        for (auto x : grid)
        {
            for (auto y : x)
            {
                if (y < 0)
                    ret++;
            }
        }

        return ret;
    }
};