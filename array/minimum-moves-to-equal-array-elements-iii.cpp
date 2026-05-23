class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxi = max(maxi, nums[i]);
        }
        int total = n*maxi;
        return total - sum;
    }
};