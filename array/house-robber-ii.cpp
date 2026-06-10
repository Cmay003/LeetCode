class Solution {
public:
    int helper(vector<int> nums, int idx, bool taken){
        if(idx==0) return (!taken)?nums[0]:0;
        if(idx<0) return 0;
        int take=(idx==nums.size()-1 || taken)?nums[idx]+helper(nums,idx-2,true):nums[idx]+helper(nums,idx-2,false);
        int notTake=helper(nums,idx-1,false);
        return max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, n-1, false);
    }
};