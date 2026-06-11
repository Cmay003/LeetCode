class Solution {
public:
    // int helper(int m, int n, vector<vector<int>>&dp){
    //     if(m==0 && n==0) return 1;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up=(m!=0)?helper(m-1,n,dp):0;
    //     int left=(n!=0)?helper(m,n-1,dp):0;
    //     return dp[m][n]=left+up;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=(i>0)?dp[i-1][j]:0;
                int left=(j>0)?dp[i][j-1]:0;
                dp[i][j]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};