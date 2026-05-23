class Solution {
public:
    long long totalTime(vector<int>& nums, int h){
        long long total = 0;
        for(int i=0; i<nums.size(); i++){
            total += (nums[i] + h - 1) / h;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(piles[i]>maxi){
                maxi = piles[i];
            }
        }
        int low=1, high=maxi;
        while(low<=high){
            int mid = (low+high)/2;
            long long total = totalTime(piles, mid);
            if(total<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};