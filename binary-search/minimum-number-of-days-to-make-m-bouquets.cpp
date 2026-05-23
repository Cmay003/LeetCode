class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k){
        int count = 0;
        int bouq = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=day) count++;
            else{
                bouq+=(count/k);
                count = 0;
            }
        }
        bouq+=(count/k);
        return (bouq>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            if(bloomDay[i]>maxi) maxi = bloomDay[i];
            if(bloomDay[i]<mini) mini = bloomDay[i];
        }
        int low = mini, high = maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};