#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int min_distance=10000;
        int closet=0;
        
        int ssize=nums.size();
        for(int i=0;i<ssize;i++){
            int two_target=target-nums[i];
            
            int m=i+1,n=ssize-1;
            while(m<n){
                int dis=two_target-(nums[m]+nums[n]);
                
                if(dis>0){
                    if(abs(dis)<min_distance){
                        min_distance=abs(dis);
                        closet=nums[m]+nums[n]+nums[i];
                    }
                    m++;
                    continue;
                }
                else if(dis<0){
                    if(abs(dis)<min_distance){
                        min_distance=abs(dis);
                        closet=nums[m]+nums[n]+nums[i];
                    }
                    n--;
                    continue;
                }
                else{
                    return nums[m]+nums[n]+nums[i];
                }
            }
        }
        return closet;
    }
};