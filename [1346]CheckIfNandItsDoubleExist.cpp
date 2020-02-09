#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> s;
        for (int x: arr)
            s[x]++;
        for (int x: arr)
            if (x != 0 && s.find(x * 2) != s.end())
                return true;
            else if (x == 0 && s[x] >= 2)
                return true;
        return false;
    }
};