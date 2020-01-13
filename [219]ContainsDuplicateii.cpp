#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto m = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = m.find(nums[i]);
            if (iter != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};