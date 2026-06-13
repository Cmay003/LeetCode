class Solution {
public:
    int helper(int row1, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        int row2=row1+col1-col2;
        if(row1<0 || row1>=grid.size() || col1<0 || col1>=grid.size() || row2<0 || row2>=grid.size() || col2<0 || col2>=grid.size()) return -1e9;
        if(grid[row1][col1]==-1 || grid[row2][col2]==-1) return -1e9;
        if(dp[row1][col1][col2]!=-1) return dp[row1][col1][col2];
        if(row1==grid.size()-1 && row2==grid.size()-1 && col1==grid.size()-1 && col2==grid.size()-1){
            if(row1==row2 && col1==col2) return grid[row1][col1];
            else return grid[row1][col1]+grid[row2][col2];
        }
        int curr;
        if(row1==row2 && col1==col2){
            curr=grid[row1][col1];
        }
        else{
            curr=grid[row1][col1]+grid[row2][col2];
        }
        int one=helper(row1,col1+1,col2+1,grid,dp);
        int two=helper(row1+1,col1,col2,grid,dp);
        int three=helper(row1,col1+1,col2,grid,dp);
        int four=helper(row1+1,col1,col2+1,grid,dp);
        return dp[row1][col1][col2]=curr+max({one,two,three,four});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        int ans=helper(0,0,0,grid,dp);
        return (ans<0)?0:ans;
    }
};