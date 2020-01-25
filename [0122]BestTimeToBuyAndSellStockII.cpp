#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,psize=prices.size(),distance=0;
        
        for(int i=0;i<psize-1;i++){
            distance=prices[i+1]-prices[i];
            if(distance>0)
                maxprofit+=distance;
        }
        
        return maxprofit;
    }
};