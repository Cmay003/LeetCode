class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1) return -1;
        queue<pair<int,pair<int,int>>> q; //{dis,{i,j}}
        q.push({1,{0,0}});
        int drow[8]={1,1,0,-1,-1,-1,0,1};
        int dcol[8]={0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1) return dis;
            for(int i=0; i<8; i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==0 && dist[row][col]>dis+1){
                    dist[row][col]=dis+1;
                    q.push({dis+1,{row,col}});
                }
            }
        }
        return -1;
    }
};