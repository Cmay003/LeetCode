class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=(i!=m-1)?helper(m,n,i+1,j,dp):0;
        int right=(j!=n-1)?helper(m,n,i,j+1,dp):0;
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};