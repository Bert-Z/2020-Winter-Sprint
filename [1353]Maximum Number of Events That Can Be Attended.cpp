#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        set<int> s;
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) {
            if (b[1] == a[1])
                return b[0] > a[0];
            else
                return b[1] > a[1];
        });
        int res = 0, i = 0;
        for (; i < events.size(); i++)
        {
            for (int j = events[i][0]; j <= events[i][1]; j++)
            {
                if (!s.count(j))
                {
                    res++;
                    s.insert(j);
                    break;
                }
            }
        }
        return res;
    }
};