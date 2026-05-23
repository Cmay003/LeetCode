class Solution {
public:
    bool helper(vector<vector<int>>&adj, int n, vector<int>&ans, int node){
        if(node==n) return true;
        for(int i=1; i<=4; i++){
            bool check=true;
            for(int j:adj[node]){
                if(ans[j]==i){
                    check=false;
                    break;
                }
            }
            if(check){
                ans[node]=i;
                if(helper(adj, n, ans, node+1)){
                    return true;
                }
                ans[node]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(int i=0; i<paths.size(); i++){
            int u=paths[i][0]-1;
            int v=paths[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n,0);
        helper(adj, n, ans, 0);
        return ans;
    }
};