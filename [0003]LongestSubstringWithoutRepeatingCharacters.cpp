// two pointers strategy

#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ssize=s.size();
        map<char,int> charplace;
        
        if(ssize<=1)
            return ssize;
        
        charplace[s[0]]=0;
        int cur_size=1,max_size=1,left=0,right=1;
        
        for(;right<ssize;right++){

            if(charplace.find(s[right])!=charplace.end()&&charplace[s[right]]>=left){
                left=charplace[s[right]]+1;
            }
            
            charplace[s[right]]=right;
            cur_size=right-left+1;
            max_size=max(cur_size,max_size);
        }

        return max_size;
    }
};