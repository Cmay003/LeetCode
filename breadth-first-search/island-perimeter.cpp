class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                    break;
                }
            }
        }
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,-1,0,1};
        int peri=0;
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==0) peri++;
            if(r==n-1) peri++;
            if(c==0) peri++;
            if(c==m-1) peri++;
            for(int i=0; i<4; i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col]){
                    if(grid[row][col]){
                        q.push({row,col});
                        visited[row][col]=1;
                    }
                    else{                    
                        peri++;
                    }
                }
            }
        }
        return peri;
    }
};