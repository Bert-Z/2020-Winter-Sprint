#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        int csize=candies.size();
        map<int,int> kinds;
        if(csize==0)
            return 0;
        
        for(int i=0;i<csize;i++)
           kinds[candies[i]]=1;
        
        if(kinds.size()>csize/2)
            return csize/2;
        else
            return kinds.size();
    }
};