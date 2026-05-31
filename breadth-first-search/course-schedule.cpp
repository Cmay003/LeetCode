class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>&visited, vector<int>&path, int i){
        visited[i]=1;
        path[i]=1;
        for(int it:adj[i]){
            if(!visited[it]) {
                if(dfs(adj, visited, path, it)) return true;
            }
            else if(path[it]){
                return true;
            }
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        vector<int> path(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]) if(dfs(adj, visited, path, i)) return false;
        }
        return true;
    }
};