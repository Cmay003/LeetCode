class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int low, int mid, int high){
        int j=mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && (long long)nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        int left=low, right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
                right++;
        }
        for(int i=low; i<=high; i++){
            nums[i]=temp[i-low];
        }
    }
    void merger(vector<int>& nums, int low, int high){
        int n=nums.size();
        if(low>=high) return;
        int mid=(low+high)/2;
        merger(nums, low, mid);        
        merger(nums, mid+1, high);
        merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        merger(nums, low, high);
        return count;
    }
};