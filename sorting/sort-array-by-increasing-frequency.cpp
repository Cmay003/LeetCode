class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b){
        if(a.first != b.first){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        vector<pair<int,int>> freq;
        for(auto it:mpp){
            freq.push_back({it.second,it.first});
        }
        sort(freq.begin(), freq.end(), comp);
        vector<int> ans;
        for(pair p:freq){
            for(int i=0; i<p.first; i++){
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};