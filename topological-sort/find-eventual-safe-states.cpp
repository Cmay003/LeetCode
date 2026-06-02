class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&state){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node]=1;    //visiting node
        for(int it:adj[node]){
            if(!dfs(it,adj,state)){
                return false;
            }
        }
        state[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //dfs
        int n=graph.size();
        vector<int> state(n,0);//0-> not visited 1->visiting/unsafe 2->safe
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(dfs(i,graph,state)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};