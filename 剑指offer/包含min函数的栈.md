```cpp
class Solution {
private:
    vector<int> s;
    int minv;
public:
    void push(int value) {
        if(s.empty())
            minv=value;
        else
            minv=std::min(minv,value);
        s.push_back(value);
    }
    void pop() {
        s.pop_back();
        minv=*min_element(s.begin(),s.end());
    }
    int top() {
        return s[s.size()-1];
    }
    int min() {
        return minv;
    }
};
```