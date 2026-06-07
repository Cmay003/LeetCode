class DisjointSet{
    
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]);
    }
    void uni(int u,int v){
        int parU=findPar(u);
        int parV=findPar(v);
        if(parU==parV) return;
        else if(size[parU]<size[parV]){
            parent[parU]=parV;
            size[parV]+=size[parU];
        }
        else{
            parent[parV]=parU;
            size[parU]+=size[parV];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds=DisjointSet(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                int drow[4]={0,-1,0,1};
                int dcol[4]={-1,0,1,0};
                for(int k=0; k<4; k++){
                    int row=drow[k]+i;
                    int col=dcol[k]+j;
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                        int node=i*n+j;
                        int adjNode=row*n+col;
                        ds.uni(node,adjNode);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                int drow[4]={0,-1,0,1};
                int dcol[4]={-1,0,1,0};
                set<int> comp;
                for(int k=0; k<4; k++){
                    int row=drow[k]+i;
                    int col=dcol[k]+j;
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                        comp.insert(ds.findPar(row*n+col));
                    }
                }
                int total=0;
                for(auto it:comp){
                    total+=ds.size[it];    
                }
                ans=max(ans,total+1);
            }
        }
        for(int cell=0; cell<n*n; cell++){
            ans=max(ans,ds.size[ds.findPar(cell)]);
        }
        return ans;
    }
};