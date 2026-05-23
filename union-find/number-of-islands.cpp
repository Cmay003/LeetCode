class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&visited, vector<vector<char>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        visited[r][c]=1;
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        for(int i=0; i<4; i++){
            int row=r+drow[i];
            int col=c+dcol[i];
            if(row>=0 && row<m && col>=0 && col<n && !visited[row][col] && grid[row][col]=='1'){
                dfs(row, col, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};