class Solution {
public:
    int helper(vector<vector<int>> &dp, vector<int> &nums, int idx, bool taken){
        if(idx==0) return (!taken)?nums[0]:0;
        if(idx<0) return 0;
        if((dp[idx][0]!=-1 && !taken)||(dp[idx][1]!=-1 && taken)){
            if(taken) return dp[idx][1];
            else return dp[idx][0];
        }
        int take=(idx==nums.size()-1 || taken)?nums[idx]+helper(dp,nums,idx-2,true):nums[idx]+helper(dp,nums,idx-2,taken);
        int notTake=helper(dp,nums,idx-1,taken);
        if(taken){
            return dp[idx][1]=max(take,notTake);
        }
        return dp[idx][0]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return dp[n-1][0]=helper(dp, nums, n-1, false);
    }
};