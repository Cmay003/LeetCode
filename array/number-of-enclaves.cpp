class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !visited[i][0]){ 
                visited[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][n-1]==1 && !visited[i][n-1]){ 
                visited[i][n-1]=1;
                q.push({i,n-1});
            }
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==1 && !visited[0][i]){ 
                visited[0][i]=1;
                q.push({0,i});
            }
            if(grid[m-1][i]==1 && !visited[m-1][i]){ 
                visited[m-1][i]=1;
                q.push({m-1,i});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[4]={0,-1,0,1};
            int dcol[4]={-1,0,1,0};
            for(int i=0; i<4; i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && !visited[row][col] && grid[row][col]==1){
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]) count++;
            }
        }
        return count;
    }
};