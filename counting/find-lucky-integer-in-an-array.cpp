class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mpp;
        int n=arr.size();
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        int maxi=-1;
        for(auto num: mpp){
            if(num.first==num.second){
                maxi=max(maxi, num.first);
            }
        }
        return maxi;
    }
};