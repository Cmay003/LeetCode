class Solution {
public:
    int helper(int idx, vector<int>&nums){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        int pick=nums[idx]+helper(idx-2, nums);
        int notPick=helper(idx-1, nums);
        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper(n-1, nums);
    }
};