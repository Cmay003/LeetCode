class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && nums[j]==nums[i]) j++;
            int large = n-j;
            if(large>=k) ans+=(j-i);
            i=j;
        }
        return ans;
    }
};