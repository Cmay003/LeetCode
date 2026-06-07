class DisjointSet{
    vector<int> parent, size;
    public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds=DisjointSet(n);
        unordered_map<string,int> mpp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.uni(mpp[mail],i);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it:mpp){
            int node=ds.findPar(it.second);
            string mail=it.first;
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};