class Solution {
public:
    int helper(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&dp){
        if(row==0 && col==0) return grid[0][0];
        if(dp[row][col]!=1e9) return dp[row][col];
        int up=(row!=0)?helper(grid, row-1, col, dp)+grid[row][col]:INT_MAX;
        int left=(col!=0)?helper(grid, row, col-1, dp)+grid[row][col]:INT_MAX;
        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,1e9));
        return helper(grid, n-1, m-1,dp);
    }
};