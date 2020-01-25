#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        vector<int> cur;
        
        for(int i=0;i<size;i++)
            if(nums[i]!=0)
                cur.push_back(nums[i]);    
        
        while(cur.size()<size)
            cur.push_back(0);
        
        nums.swap(cur);
    }
};