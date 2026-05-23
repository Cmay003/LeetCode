class Solution {
public:
    int dayy(vector<int> &arr, int capacity){
        int load=0, day=1;
        for(int i=0; i<arr.size(); i++){
            if(load+arr[i]>capacity){
                day++;
                load=arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, weights[i]);
            sum+=weights[i];
        }
        int low=maxi, high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int daysReq = dayy(weights, mid);
            if(daysReq<=days){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};