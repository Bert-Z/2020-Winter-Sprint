#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ssize=strs.size();
        
        if(!ssize)
            return "";
        
        auto it = strs.begin();
        
        string common_prefix=*it;
        
        it++;
        
        for(;it!=strs.end();it++){
            helper(common_prefix,*it);
            if(common_prefix.size()==0)
                break;
        }
        
        return common_prefix;
    }
    
    void helper(string & prefix, const string & str){
        int minsize=min(prefix.size(),str.size());
        
        int i=0;
        for(;i<minsize;i++){
            if(str[i]!=prefix[i])
                break;
        }
        
        prefix=prefix.substr(0,i);
        
        return;
    }
};