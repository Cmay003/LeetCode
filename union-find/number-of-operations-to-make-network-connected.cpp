class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]);
    }
    void unionBySize(int u, int v){
        int paru=findPar(u);
        int parv=findPar(v);
        if(paru==parv) return;
        else if(size[paru]<size[parv]){
            parent[paru]=parv;
            size[parv]+=size[paru];
        }
        else{
            parent[parv]=paru;
            size[paru]+=size[parv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds=DisjointSet(n);
        int total=connections.size();
        if(total<n-1) return -1;
        int ans=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionBySize(u,v);
                ans++;
            }
        }
        int count=-1;
        for(int i=0; i<n; i++){
            if(ds.findPar(i)==i) count++;
        }
        return count;
    }
};