#include <bits/stdc++.h>

using namespace std;

class RLEIterator
{
public:
    RLEIterator(vector<int> &A)
    {
        evector.assign(A.begin(), A.end());
    }

    int next(int n)
    {
        int count = 0, ssize = evector.size(), i = 0, minus = 0, ret = -1;
        for (; i < ssize - 1; i = i + 2)
        {
            if (evector[i] == 0)
                continue;

            if (n - count > evector[i])
            {
                count += evector[i];
                continue;
            }
            else if (n - count == evector[i])
            {
                count += evector[i];
                ret = evector[i + 1];
                i = i + 2;
                break;
            }
            else if (n - count < evector[i])
            {
                minus = n - count;
                count = n;
                ret = evector[i + 1];
                break;
            }
        }

        if (count != n)
        {
            evector.clear();
            return ret;
        }

        evector.erase(evector.begin(), evector.begin() + i);
        evector[0] -= minus;
        cout << "nums: " << evector[0] << " now: " << evector[1] << endl;
        return ret;
    }

private:
    vector<int> evector;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */