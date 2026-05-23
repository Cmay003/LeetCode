class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi = 2;
       for(int i=0; i<nums.size()-2; i++){
           int k = i+2;
           while(k<nums.size() && nums[k]==nums[k-1]+nums[k-2]){
               k++;
           }
           maxi = max(maxi, k-i);
       }
        return maxi;
    }
};