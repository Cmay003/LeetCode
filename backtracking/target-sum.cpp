class Solution {
public:
    int helper(vector<int>&nums, int target, int idx, int sum, vector<vector<int>> &dp, int s){
        if(idx==-1) return (sum==target)?1:0;
        if(dp[idx][sum+s]!=-1) return dp[idx][sum+s];
        int pos=helper(nums,target,idx-1,sum+nums[idx],dp,s);
        int neg=helper(nums,target,idx-1,sum-nums[idx],dp,s);
        return dp[idx][sum+s]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return helper(nums,target,n-1,0,dp,sum);
    }
};