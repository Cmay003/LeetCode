class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]);
    }
    void uni(int u, int v){
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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>> pos(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pos[grid[i][j]]={i,j};
            }
        }
        DisjointSet ds=DisjointSet(n*n);
        for(int t=0; t<n*n; t++){
            auto [r,c]=pos[t];
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,-1,0,1};
            for(int i=0; i<4; i++){
                int row=drow[i]+r; 
                int col=dcol[i]+c; 
                if(row>=0 && row<n && col>=0 && col<n && grid[row][col]<=t){
                    int p1=r*n+c;
                    int p2=row*n+col;
                    if(ds.findPar(p1)!=ds.findPar(p2)){
                        ds.uni(p1,p2);
                    }
                }
            }
            if(ds.findPar(0)==ds.findPar(n*n-1)) return t;
        }
        return -1;
    }
};