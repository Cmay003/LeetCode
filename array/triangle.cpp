class Solution {
public:
    // int helper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>&dp){
    //     if(row==triangle.size()-1) return triangle[row][col];
    //     if(dp[row][col]!=1e9) return dp[row][col];
    //     int left=triangle[row][col]+helper(triangle,row+1,col,dp);
    //     int right=triangle[row][col]+helper(triangle,row+1,col+1,dp);
    //     return dp[row][col]=min(left,right);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int col=0; col<n; col++){
            dp[n-1][col]=triangle[n-1][col];
        }
        for(int row=n-2; row>=0; row--){
            for(int col=0; col<=row; col++){
                int left=triangle[row][col]+dp[row+1][col];
                int right=triangle[row][col]+dp[row+1][col+1];
                dp[row][col]=min(left,right);
            }
        }
        return dp[0][0];
    }
};