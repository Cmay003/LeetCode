class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        float avg=0;
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            avg+=nums[i];
            mini=min(mini, nums[i]);
            maxi=max(maxi, nums[i]);
        }
        avg=avg/n;
        map<int, int> mpp;

        for(int i=1; i<=abs(maxi)+1; i++){
            auto it = find(nums.begin(), nums.end(), i);
            if(it==nums.end()){
                if(i>avg) return i;
            }
        }
        return -1;
    }
};