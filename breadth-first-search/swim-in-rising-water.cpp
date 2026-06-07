class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
    void dfs(int n, vector<vector<int>>& grid, vector<vector<int>>&visited, int i, int j, int t){
        visited[i][j]=1;
        for(int k=0; k<4; k++){
            int row=drow[k]+i;
            int col=dcol[k]+j;
            if(row>=0 && row<n && col>=0 && col<n && !visited[row][col] && grid[row][col]<=t){
                dfs(n, grid, visited, row, col, t);
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=0, high=n*n-1;
        while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>> visited(n,vector<int>(n,0));
            dfs(n, grid, visited, 0, 0, mid);
            if(visited[n-1][n-1]) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};