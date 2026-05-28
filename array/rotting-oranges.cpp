class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        int time=0;
        while(!q.empty() && fresh>0){
            int size=q.size(); time++;
            for(int i=0; i<size; i++){
                auto [r,c]=q.front(); q.pop();
                for(int j=0; j<4; j++){
                    int row=drow[j]+r;
                    int col=dcol[j]+c;
                    if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1){
                        fresh--;
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                }
            }
        }
        return (!fresh)?time:-1;
    }
};