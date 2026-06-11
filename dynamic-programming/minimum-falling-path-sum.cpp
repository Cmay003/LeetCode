class Solution {
public:
    int helper(vector<vector<int>>& matrix, int n, int row, int col, vector<vector<int>>& dp){
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=1e9) return dp[row][col];
        int left=INT_MAX, mid=INT_MAX, right=INT_MAX;
        if(col>0) left=matrix[row][col]+helper(matrix,n,row+1,col-1,dp);
        mid=matrix[row][col]+helper(matrix,n,row+1,col,dp);
        if(col!=n-1) right=matrix[row][col]+helper(matrix,n,row+1,col+1,dp);
        return dp[row][col]=min({left,mid,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int i=0; i<n; i++){
            ans=min(ans,helper(matrix,n,0,i,dp));
        }
        return ans;
    }
};