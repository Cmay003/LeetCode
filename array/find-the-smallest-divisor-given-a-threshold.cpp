class Solution {
public:
    bool isPossible(vector<int>& arr, int num, int t){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=ceil((double)arr[i]/(double)num);
        }
        return (sum<=t);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0; i<n; i++){
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
        }
        int low=1, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(nums, mid, threshold)){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};