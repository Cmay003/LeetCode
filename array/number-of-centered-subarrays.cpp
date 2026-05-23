class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int sum=0;
            map<int, int> mpp;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                mpp[nums[j]]++;
                if(mpp[sum]!=0){
                    ans++;
                }
            }
        }
        return ans;
    }
};