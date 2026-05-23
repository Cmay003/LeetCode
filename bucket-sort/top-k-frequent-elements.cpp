class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return {nums[0]};
        map<int, int> mpp;
        vector<int> values;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            values.push_back(it.second);
        }
        sort(values.begin(), values.end(), greater<int>());
        set<int> ansTmp;
        for(int i=0; i<k; i++){
            for(auto it:mpp){
                if(it.second==values[i]){
                    ansTmp.insert(it.first);
                } 
            }
        }
        vector<int> ans(ansTmp.begin(), ansTmp.end());
        return ans;
    }
};