class Solution {
public:
bool isPossible(vector<int> &arr, int dis, int m){
    int balls=1;
    int last=arr[0];
    for(int i=0; i<arr.size(); i++){
        if(arr[i]-last>=dis){
            balls++;
            last=arr[i];
        }
        if(balls==m) return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int maxi = position[n-1]-position[0];
        int low=1, high=maxi;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(position, mid, m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};