class Solution {
public:
    const int MOD=1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> time(n,1e18);
        time[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> ways(n,0);
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long times=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjTime=it.second;
                int adjNode=it.first;
                if(adjTime+times<=time[adjNode]){
                    if(adjTime+times==time[adjNode]){
                        ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                    }
                    else{
                        ways[adjNode]=ways[node];
                        time[adjNode]=adjTime+times;
                        pq.push({adjTime+times,adjNode});
                    }
                }
            }
        }
        return ways[n-1];
    }
};