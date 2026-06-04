class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); //{dest, price}
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> price(n,1e9);
        price[src]=0;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            int stops=pq.top().first;
            int prc=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            for(auto it:adj[node]){
                int adjPrice=it.second;
                int adjNode=it.first;
                if(adjPrice+prc<price[adjNode] && stops<=k){
                    price[adjNode]=adjPrice+prc;
                    pq.push({stops+1,{adjPrice+prc,adjNode}});
                }
            }
        }
        return (price[dst]==1e9)?-1:price[dst];
    }
};