class Solution {
public:
    int minimisedSum(vector<int>&arr, int sums){
        int subs=1;
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]+sum <= sums){
                sum+=arr[i];
            }
            else{
                subs++;
                sum=arr[i];
            }
        }
        return subs;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=nums[0];
        int high=0;
        for(int i=0; i<n; i++){
            low=max(low, nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(minimisedSum(nums, mid)<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};