#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ssize=nums.size();
        unordered_set<int> chosen;
        
        vector<vector<int>> ret;
        
        for(int i=0;i<ssize-1;i++){
            int left=i+1,right=ssize-1;
            int need=0-nums[i];
            if(chosen.count(nums[i])!=0)
                continue;
            
            chosen.insert(nums[i]);
            
            unordered_set<int> chosen2;
            while(left<right){
                int now=nums[left]+nums[right];
                
                if(chosen2.count(nums[left])||now<need)
                    left++;
                else if(chosen2.count(nums[right])||now>need)
                    right--;
                else if(now==need){
                    vector<int> ok={nums[i],nums[left],nums[right]};
                    ret.push_back(move(ok));
                    chosen2.insert(nums[right]);
                    chosen2.insert(nums[left]);
                    left++;
                }    
            }
        }
        
        return ret;
    }
};