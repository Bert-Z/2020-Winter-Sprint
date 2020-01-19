#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> oneD;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                oneD.push_back(grid[i][j]);
        
        int osize=oneD.size();
        k=osize-k%osize;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid[i][j]=oneD[k%osize];
                k++;
            }
        }
        return grid;
    }
};