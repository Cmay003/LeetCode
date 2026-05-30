class Solution {
public:
    const int drow[4]={-1,0,1,0};
    const int dcol[4]={0,-1,0,1};
    void dfs(int n, int m, vector<vector<int>>& grid, vector<vector<int>>&visited, int &temp, int i, int j){
        visited[i][j]=1;
        temp++;
        for(int k=0; k<4; k++){
            int row=drow[k]+i;
            int col=dcol[k]+j;
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col] && !visited[row][col]){
                dfs(n, m, grid, visited, temp, row, col);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int temp=0;
                if(grid[i][j] && !visited[i][j]){
                    dfs(n, m, grid, visited, temp, i, j);
                    ans=max(temp,ans);
                }
            }
        }
        return ans;
    }
};