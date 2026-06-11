class Solution {
public:
    // int helper(vector<vector<int>>& matrix, int n, int row, int col, vector<vector<int>>& dp){
    //     if(row==n-1) return matrix[row][col];
    //     if(dp[row][col]!=1e9) return dp[row][col];
    //     int left=INT_MAX, mid=INT_MAX, right=INT_MAX;
    //     if(col>0) left=matrix[row][col]+helper(matrix,n,row+1,col-1,dp);
    //     mid=matrix[row][col]+helper(matrix,n,row+1,col,dp);
    //     if(col!=n-1) right=matrix[row][col]+helper(matrix,n,row+1,col+1,dp);
    //     return dp[row][col]=min({left,mid,right});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        vector<int> prev(n,0);
        for(int i=0; i<n; i++){
            prev[i]=matrix[0][i];
        }
        for(int row=1; row<n; row++){
            vector<int> curr(n);
            for(int col=0; col<n; col++){
                int left=(col>0)?matrix[row][col]+prev[col-1]:1e9;
                int mid=matrix[row][col]+prev[col];
                int right=(col!=n-1)?matrix[row][col]+prev[col+1]:1e9;
                curr[col]=min({left,mid,right});
            }
            prev=curr;
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,prev[i]);
        }
        return ans;
    }
};