#include<stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n==0)
            return 0;
        int ret=0;
        
        for(int i=1;i<=32;i++){
            ret+=(((n<<(32-i))>>31)<<(32-i));
        }
        
        return ret;
    }
};