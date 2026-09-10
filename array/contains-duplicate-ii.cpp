class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(abs(mpp[nums[i]].back()-i)<=k) return true;
            }
            mpp[nums[i]].push_back(i);
        }
        return false;
    }
};