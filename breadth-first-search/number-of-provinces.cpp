class Solution {
public:
    void dfs(int s, vector<vector<int>>&adj, vector<int>&visited){
        visited[s]=1;
        for(int num:adj[s]){
            if(!visited[num]){
                dfs(num, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int count=0;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};