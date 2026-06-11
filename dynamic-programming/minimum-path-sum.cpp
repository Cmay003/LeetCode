class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& grid){
        if(m==0 && n==0) return grid[m][n];
        int left=(n>0)?grid[m][n]+helper(m,n-1,grid):INT_MAX;
        int up=(m>0)?grid[m][n]+helper(m-1,n,grid):INT_MAX;
        return min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return helper(m-1,n-1,grid);
    }
};