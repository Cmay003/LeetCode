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
        vector<int> prev(n,-1);
        for(int i=0; i<m; i++){
            vector<int> curr(n);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    curr[j]=1;
                    continue;
                }
                int up=(i>0)?prev[j]:0;
                int left=(j>0)?curr[j-1]:0;
                curr[j]=left+up;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};