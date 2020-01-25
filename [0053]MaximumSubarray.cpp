#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        
        int ri=0,partialSum=0,maxSum=0;
        int largestNum=nums[0];
        
        for(int i=0;i<nums.size();i++){
            ri=nums[i];
            
            if(largestNum<ri)
                largestNum=ri;
            
            partialSum+=ri;
            if(partialSum>maxSum)
                maxSum=partialSum;
            
            if(partialSum<0)
                partialSum=0;
        }
        
        return (maxSum==0)?largestNum:maxSum;
    }
};