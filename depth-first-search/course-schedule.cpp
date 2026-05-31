class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>&visited, int i){
        visited[i]=1;
        for(int it:adj[i]){
            if(!visited[it]) dfs(adj, visited, it);
            else return false;
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(!dfs(adj, visited, i)) return false;
        }
        return true;
    }
};