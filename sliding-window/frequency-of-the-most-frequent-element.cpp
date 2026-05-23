class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum=0, res=0, l=0, r=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(nums[r]*(r-l+1)> sum+k){
                sum-=nums[l];
                l+=1;
            }
            res=max(res, r-l+1);
            r+=1;
        }

        return res;
        
    }
};