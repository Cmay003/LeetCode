class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0]=0;
        pq.push({0,{0,0}});
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        int ans=-1;
        while(!pq.empty()){
            int eff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0; i<4; i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(row>=0 && row<n &&col>=0 &&col<m){
                    int diff=abs(heights[r][c]-heights[row][col]);
                    int newEff=max(eff,diff);
                    if(newEff<effort[row][col]){
                        effort[row][col]=newEff;
                        pq.push({newEff,{row,col}});                        
                    }                    
                }
            }
        }
        return effort[n-1][m-1];
    }
};