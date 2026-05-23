class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adj(V);
        vector<int> inorder(V,0);
        for(int i=0; i<V; i++){
            for(int it:graph[i]){
                adj[it].push_back(i);
            }
            inorder[i]=graph[i].size();
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inorder[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            ans.push_back(num);
            for(int x:adj[num]){
                inorder[x]--;
                if(inorder[x]==0) q.push(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};