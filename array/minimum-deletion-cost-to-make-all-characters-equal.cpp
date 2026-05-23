class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char, long long> mpp;
        long long total=0;
        for(int i=0; i<cost.size(); i++){
            mpp[s[i]]+=cost[i];
            total+=cost[i];
        }
        long long maxi=0;
        for(auto it:mpp){
            maxi=max(maxi, it.second);
        }
        return total-maxi;
    }
};