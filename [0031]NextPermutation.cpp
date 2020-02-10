#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ssize=nums.size();
        int i=ssize-1;
        bool flag=true;
        
        while(i>0){
            if(nums[i]<=nums[i-1]){
                i--;
                continue;
            }
                
            flag=false;
            int j=ssize-1;
            for(;j>i-1;j--)
                if(nums[j]>nums[i-1])
                    break;
            
            swap(nums[i-1],nums[j]);
            
            reverse(nums.begin()+i,nums.end());
            break;
        }
        
        if(flag)
            reverse(nums.begin(),nums.end());
        
        return;
    }
    
};