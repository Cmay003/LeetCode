class Solution {
public:
    void dfs(vector<vector<int>>&adj, int idx, vector<int>&visited){
        visited[idx]=1;
        for(int it:adj[idx]){
            if(!visited[it]){
                dfs(adj, it, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int sum=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                sum++;
                dfs(adj,i, visited);
            }
        }
        return sum;
    }
};