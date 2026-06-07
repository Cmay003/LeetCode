class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> times(n, vector<int>(n,1e9));
        times[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(time>times[row][col]) continue;
            if(row==n-1 && col==n-1) return time;
            pq.pop();
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,-1,0,1};
            for(int i=0; i<4; i++){
                int nr=drow[i]+row;
                int nc=dcol[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newTime=max(time,grid[nr][nc]);
                    if(newTime<times[nr][nc]){
                        times[nr][nc]=newTime;
                        pq.push({newTime,{nr,nc}});
                    }                    
                }
            }
        }
        return times[n-1][n-1];
    }
};