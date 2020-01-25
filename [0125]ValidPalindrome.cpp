#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        for(auto it=s.begin();it!=s.end();it++){
            if(!isalpha(*it)&&!isdigit(*it)){
                s.erase(it);
                it--;
            }
        }
        
        string rs;
        rs.assign(s.rbegin(),s.rend());

        if(s.compare(rs)==0)
            return true;
        return false;
    }
};