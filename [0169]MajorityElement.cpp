#include<vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate=nums[0];
        int number=0;
        
        for(auto it=nums.begin();it!=nums.end();it++){
            if(*it==candidate)
                number++;
            else
                number--;
            
            if(number<=0){
                number=0;
                candidate=*(it+1);
            }
        }
        if(number>0)
            return candidate;
        return 0;
    }
    
};