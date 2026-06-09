class Solution {
public:
    int helper(int idx, vector<int>&nums, vector<int>&dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+helper(idx-2, nums, dp);
        int notPick=helper(idx-1, nums, dp);
        return dp[idx]=max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(n-1, nums, dp);
    }
};