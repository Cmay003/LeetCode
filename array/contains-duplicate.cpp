class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mpp;
        for(int num:nums){
            if(mpp.count(num) > 0) return true;
            mpp.insert(num);
        }
        return false;
    }
};