class DisjointSet{
    vector<int> parent,size;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int row=0, col=0;
        for(auto it:stones){
            row=max(row,it[0]);
            col=max(col,it[1]);
        }
        DisjointSet ds=DisjointSet(row+col+2);
        unordered_map<int,int> mpp;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+row+1;
            ds.unionBySize(nodeRow,nodeCol);
            mpp[nodeRow]=1;
            mpp[nodeCol]=1;
        }
        int count=0;
        for(auto it:mpp){
            if(ds.findPar(it.first)==it.first) count++;
        }
        return n-count;
    }
};