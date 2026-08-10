class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int prod=1;
        int zero=1;
        int cnt=0;
        for(int i:nums){
            if(i==0){
                if(zero==0) cnt++;
                else zero=0;
            }
            else prod*=i;
        }
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(cnt>1) ans[i]=0;
                else ans[i]=prod;
            }
            else ans[i]=zero*prod/nums[i];
        }
        return ans;
    }
};