class Solution {
public:
    int helper(vector<vector<int>>& triangle, int row, int col){
        if(row==triangle.size()-1) return triangle[row][col];
        int left=(col<triangle[row].size())?triangle[row][col]+helper(triangle,row+1, col):INT_MAX;
        int right=(col<triangle[row].size())?triangle[row][col]+helper(triangle,row+1, col+1):INT_MAX;
        return min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return helper(triangle,0,0);
    }
};