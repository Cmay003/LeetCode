class Solution {
public:
    bool dfs(int node, int val, vector<vector<int>>& graph, vector<int>&visited){
        visited[node]=val;
        for(int num:graph[node]){
            if(val==0){
                if(visited[num]==0) return false;
                else if(visited[num]==-1){ 
                    if (!dfs(num, 1, graph, visited)) return false;
                }
            }
            else if(val==1){
                if(visited[num]==1) return false;
                else if(visited[num]==-1){
                    if (!dfs(num, 0, graph, visited)) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0; i<n; i++){
            if(visited[i]==-1){
                if(!dfs(i, 0, graph, visited)) return false;
            }
        }
        return true;
    }
};