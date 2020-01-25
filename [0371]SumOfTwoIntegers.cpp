class Solution {
public:
    int getSum(int a, int b) {     
        int up=0,ret=0;
        
        for(int i=0;i<32;i++){
            int bita=getBit(a,i);
            int bitb=getBit(b,i);
            
            if(up){
                if(bita==bitb){
                    setBit(ret,i,true);
                    if(bita==0)
                        up=0;
                }
            }else{
                if(bita==1&&bitb==1)
                    up=1;
                else
                    if(bita==1||bitb==1)
                        setBit(ret,i,true);
            }
        }
        
        return ret;
    }
    
    inline int getBit(const int &a, const int &bitnum){
        return ((a>>bitnum)&1);
    }
    
    inline void setBit(int &a, const int &bitnum, const bool &ifsetone){
        if(ifsetone)
            a=a|(1<<bitnum);
    }
};