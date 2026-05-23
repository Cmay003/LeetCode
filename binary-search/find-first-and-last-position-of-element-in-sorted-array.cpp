class Solution {
public:
    int lowers(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int uppers(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowers(nums, target);
        int upper = uppers(nums, target)-1;
        if(lower == nums.size() || nums[lower]!=target) return {-1,-1};
        vector<int> ans = {lower, upper};
        return ans;
    }
};