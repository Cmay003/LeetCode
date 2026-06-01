class Solution {
public:
    const int drow[4]={-1,0,1,0};
    const int dcol[4]={0,-1,0,1};
    void dfs(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&visited, int i, int j){
        visited[i][j]=1;
        grid[i][j]=0;
        for(int k=0; k<4; k++){
            int row=drow[k]+i;
            int col=dcol[k]+j;
            if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]){
                dfs(n, m,grid, visited, row, col);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++){
            if(!visited[i][0] && grid[i][0]){
                dfs(n, m, grid, visited, i, 0);
            }
            if(!visited[i][m-1] && grid[i][m-1]){
                dfs(n, m, grid, visited, i, m-1);
            }
        }
        for(int i=0; i<m; i++){
            if(!visited[0][i] && grid[0][i]){
                dfs(n, m,grid, visited, 0, i);
            }
            if(!visited[n-1][i] && grid[n-1][i]){
                dfs(n, m,grid, visited, n-1, i);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]) count++;
            }
        }
        return count;
    }
};