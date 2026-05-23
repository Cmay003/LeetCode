class Solution {
public:
    void helper(vector<int>&nums, vector<vector<int>>&ans, vector<int> temp, int idx){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        helper(nums, ans, temp, idx+1);
        temp.push_back(nums[idx]);
        helper(nums, ans, temp, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, {}, 0);
        return ans;
    }
};