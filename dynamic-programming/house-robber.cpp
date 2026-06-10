class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            int pick=(i>1)?nums[i]+dp[i-2]:nums[i];
            int notP=dp[i-1];
            dp[i]=max(pick,notP);
        }
        return dp[n-1];
    }
};