class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int curr = 1;
        int prv = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]<nums[i+1]) curr++;
            else{
                prv = curr;
                curr = 1;
            }
            if(curr >= 2*k) return true;
            if(min(prv, curr)>=k) return true;
        }
        return false;
    }
};