#include<stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        for(int i=0;i<32;i++)
            if(((n>>i)&1)!=0)
                num++;
        
        return num;
    }
};