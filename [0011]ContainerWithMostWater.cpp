/**
 * Algorithm
 * The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line. Further, the farther the lines, the more will be the area obtained.
 * We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. Futher, we maintain a variable \text{maxarea}maxarea to store the maximum area obtained till now. At every step, we find out the area formed between them, update \text{maxarea}maxarea and move the pointer pointing to the shorter line towards the other end by one step.
 * 
 * A simple proof:
 * case hi <= hj:
 * we can prove that j is the best choice(within the range from i to j) for i
 * for any k(i < k < j):
 * area(i, j) == min(hi, hj)*(j-i) == hi*(j-i) > hi*(k-i) >= min(hi,hk)*(k-i) == area(i, k)
 * then we have area(i, j) > area(i, k)
 * it means j is the best choice for i, area(i,j)= largest_area_involves_i
 * so, max_area_of_range(i, j) == max(max_area_of_range(i+1, j), largest_area_involves_i)
 * case hi >= hj:
 * similarly, we can prove that max_area_of_range(i, j) == max(max_area_of_range(i+1, j), area(i, j))
 **/

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ssize=height.size();
        
        int left=0,right=ssize-1;
        int max_water=0;
        
        while(left<right){
            
            max_water=max(max_water,min(height[left],height[right])*(right-left));
            
            if(height[left]<=height[right])
                left++;
            else
                right--;
            
        }
        
        return max_water;
    }
};