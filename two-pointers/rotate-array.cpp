class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        nums.reverse(nums.begin(), nums.begin()+(n-1-k));
        nums.reverse(nums.begin()+(n-k), nums.end());
        nums.reverse(nums.begin(), nums.end());    
    }    
};