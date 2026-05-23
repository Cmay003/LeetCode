class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, int> mpp;
        int n=nums.size();
        vector<int> ans;
        for(int i=1; i<=n; i++){
            mpp[i]=0;
        }
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==0) ans.push_back(it.first);
        }
        return ans;
    }
};