#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &A)
    {
        long total = 0;
        int n = A.size(), a;
        for (int a : A)
            total += a;
        sort(A.begin(), A.end());
        while (true)
        {
            a = A[n - 1];
            if (a == 1)
                return true;
            total -= a;
            if (a <= total)
                return false;
            a -= total;
            total += a;
            A[n - 1] = a;
            sort(A.begin(), A.end());
        }
    }
};