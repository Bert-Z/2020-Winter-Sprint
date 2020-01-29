#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long count=0;
        vector<long> dvec;
        bool check=false;
        
        if(dividend==-2147483648 && divisor==1){
            return -2147483648;
        }
        
        if((dividend>=0&&divisor>0)||(dividend<=0&&divisor<0))
            check=true;
        
        long divid=abs((long)dividend);
        long divis=abs((long)divisor);
        
        while(divis<=divid){
            dvec.push_back(divis);
            divis+=divis;
        }
        
        int ssize=dvec.size();
        
        for(int i=ssize-1;i>=0;i--){
            long nowdi=dvec[i];

            while(divid-nowdi>=0){
                count+=1<<i;
                
                divid-=nowdi;
            } 
        }
        
        if(count<0){
            return 2147483647;
        }
        
        return (check)?count:-count;
    }
};