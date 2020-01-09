#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        int size=1;
        int cur=nums[0];
        
        for(auto it=nums.begin()+1;it!=nums.end();it++){
            
            if(!(cur^(*it))){
                nums.erase(it);
                it--;
            }
            else{
                size++;
                cur=*it;
            }
        }
        
        return size;
    }
};