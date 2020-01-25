#include<set>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2,s;
        vector<int> ret;
        for(auto n : nums1)
            s1.insert(n);
        for(auto n : nums2)
            s2.insert(n);
        
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s,s.begin()));
        
        for(auto it=s.begin();it!=s.end();it++)
            ret.push_back(*it);
        
        return ret;
    }
};