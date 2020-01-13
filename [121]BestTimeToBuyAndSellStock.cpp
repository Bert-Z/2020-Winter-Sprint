#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int psize=prices.size();
        
        if(prices.empty()){
            return 0;
        }
        
        int l=0,r=1;
        int maxprofit=0;
        
        for(;l<psize-1;l++){
            int lv=prices[l];
            
            int maxrv=lv;
            for(r=l+1;r<psize;r++){
                if(prices[r]>maxrv)
                    maxrv=prices[r];
            }
            
            maxprofit=((maxrv-lv)>maxprofit)?(maxrv-lv):maxprofit;
        }
        
        return maxprofit;
    }
};