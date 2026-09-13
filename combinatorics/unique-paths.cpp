class Solution {
public:
    int helper(int m, int n, vector<int>&dp){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=(m==0)?0:helper(m-1,n);
        int left=(n==0)?0:helper(m,n-1);
        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(m*n, -1);
        return helper(m-1,n-1, dp);
    }
};