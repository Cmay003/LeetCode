class Solution {
public:
    int helper(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
        if(row<0 || row>grid.size()-1 || col1<0 || col1>grid[0].size()-1 || col2<0 || col2>grid[0].size()-1){
            return -1e9;
        }
        if(row==grid.size()-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int maxi=-1e9;
        for(int i=-1; i<2; i++){
            int move=0;
            for(int j=-1; j<2; j++){
                if(col1==col2) move=grid[row][col1];
                else move=grid[row][col1]+grid[row][col2];
                move+=helper(row+1, col1+i, col2+j, grid,dp);
                maxi=max(maxi,move);
            }            
        }
        return dp[row][col1][col2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return helper(0,0,c-1,grid,dp);
    }
};