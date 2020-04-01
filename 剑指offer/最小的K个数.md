```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto x : input)
            pq.push(x);
        
        vector<int> ret;
        for(int i=0;i<k;i++){
            if(pq.empty())
                return vector<int>();
            ret.push_back(pq.top());
            pq.pop();
        }
        
        return ret;
    }
};
```