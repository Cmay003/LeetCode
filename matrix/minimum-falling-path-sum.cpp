class Solution {
public:
    int helper(vector<vector<int>>& matrix, int n, int row, int col){
        if(row==n-1) return matrix[row][col];
        int left=INT_MAX, mid=INT_MAX, right=INT_MAX;
        if(col>0) left=matrix[row][col]+helper(matrix,n,row+1,col-1);
        mid=matrix[row][col]+helper(matrix,n,row+1,col);
        if(col!=n-1) right=matrix[row][col]+helper(matrix,n,row+1,col+1);
        return min({left,mid,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        return min({helper(matrix,n,0,0),helper(matrix,n,0,1),helper(matrix,n,0,0)});
    }
};