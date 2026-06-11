class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(m==0 && n==0) return 1;
        if(grid[m][n]==1) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int left=(n>0)?helper(m,n-1,grid,dp):0;
        int up=(m>0)?helper(m-1,n,grid,dp):0;
        return dp[m][n]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);
    }
};