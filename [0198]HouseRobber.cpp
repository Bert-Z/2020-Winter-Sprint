#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        
        vector<int> L;
        for(int i=0;i<nums.size();i++){
            if(i==0)
                L.push_back(nums[i]);
            else if(i==1)
                L.push_back(max(nums[i],nums[i-1]));
            else
                L.push_back(max(L[i-1],L[i-2]+nums[i]));
        }
        return L[size-1];
    }
};