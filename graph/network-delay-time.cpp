class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int nodeTime=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjTime=it.second;
                int adjNode=it.first;
                if(adjTime+nodeTime<time[adjNode]){
                    time[adjNode]=adjTime+nodeTime;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int ans=-1;
        for(int i=1; i<=n; i++){
            ans=max(ans,time[i]);
        }
        return (ans==1e9)?-1:ans;
    }
};