```cpp
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        
        int l=0,r=array.size()-1;
        
        while(l<r){
            if(array[l]+array[r]==sum){
                ret.push_back(array[l]);
                ret.push_back(array[r]);
                return ret;
            }
            else if(array[l]+array[r]>sum){
                r--;
            }
            else{
                l++;
            }
        }
        
        return ret;
    }
};
```