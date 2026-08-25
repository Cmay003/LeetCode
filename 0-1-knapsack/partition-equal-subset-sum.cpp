class Solution {
public:
    bool helper(vector<int>& nums, int idx, int target, vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0) return target==nums[0];
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notTake=helper(nums,idx-1,target,dp);
        int take=false;
        if(target>=nums[idx]){
            take=helper(nums,idx-1,target-nums[idx],dp);
        }
        return dp[idx][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(nums,n-1,sum/2,dp);
    }
};