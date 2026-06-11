class Solution {
public:
    // int helper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp){
    //     if(m==0 && n==0) return grid[m][n];
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int left=(n>0)?grid[m][n]+helper(m,n-1,grid,dp):INT_MAX;
    //     int up=(m>0)?grid[m][n]+helper(m-1,n,grid,dp):INT_MAX;
    //     return dp[m][n]=min(left, up);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> curr(n);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    curr[j]=grid[i][j];
                    continue;
                }
                int right=(j>0)?grid[i][j]+curr[j-1]:INT_MAX;
                int down=(i>0)?grid[i][j]+prev[j]:INT_MAX;
                curr[j]=min(right,down);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};