class Solution {
public:
    int helper(vector<vector<int>>&grid, int row, int col){
        if(row==0 && col==0) return grid[0][0];
        int up=(row!=0)?helper(grid, row-1, col)+grid[row][col]:INT_MAX;
        int left=(col!=0)?helper(grid, row, col-1)+grid[row][col]:INT_MAX;
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return helper(grid, n-1, m-1);
    }
};