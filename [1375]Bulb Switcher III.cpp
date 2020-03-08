#include <vector>

using namespace std;

class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int sum = 0;
        int ssize = light.size();
        int count = 0;
        for (int i = 0; i < ssize; i++)
        {
            sum += light[i] - i - 1;
            if (sum == 0)
                count++;
        }

        return count;
    }
};