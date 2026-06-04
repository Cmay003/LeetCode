class Solution {
public:
    const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>time(n,1e9);
        time[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        vector<int> ways(n,1);
        while(!pq.empty()){
            int nodeTime=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjTime=it.second;
                int adjNode=it.first;
                if(adjTime+nodeTime<=time[adjNode]){
                    if(adjTime+nodeTime==time[adjNode]) ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                    else{
                        ways[adjNode]=ways[node];
                        time[adjNode]=adjTime+nodeTime;
                        pq.push({adjTime+nodeTime,adjNode});
                    } 
                }
            }
        }
        return ways[n-1];
    }
};