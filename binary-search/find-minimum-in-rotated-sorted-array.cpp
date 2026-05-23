class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            //left sorted
            if(nums[low]<=nums[mid]){
                mini = min(nums[low],mini);
                low=mid+1;
            }
            //right sorted
            else{
                mini = min(nums[mid], mini);
                high = mid-1;
            }
        }
        return mini;
    }
};