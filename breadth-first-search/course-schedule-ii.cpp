class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        for(auto it:prerequisites){
            int u=it[0], v=it[1];
            adj[v].push_back(u);
        }
        vector<int> inorder(V,0);
        for(auto it:prerequisites){
            inorder[it[0]]++;
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
        if (ans.size()==V) return ans;
        return {};
    }
};