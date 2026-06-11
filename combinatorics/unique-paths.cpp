class Solution {
public:
    int helper(int m, int n, vector<vector<int>>&dp){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=(m!=0)?helper(m-1,n,dp):0;
        int left=(n!=0)?helper(m,n-1,dp):0;
        return dp[m][n]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};