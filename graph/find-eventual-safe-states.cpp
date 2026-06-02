class Solution {
public:
    vector<int> topo(vector<vector<int>>&adj, int V){
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adjRev(n);
        for(int i=0; i<n; i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
            }
        }
        return topo(adjRev, n);
    }
};