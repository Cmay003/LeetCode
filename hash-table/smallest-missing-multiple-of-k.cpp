class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> ans;
        
        for(int i=0; i<n; i++){
            if(nums[i]%k==0){
                ans.insert(nums[i]);
            }
        }
        int mini = k;
        while(true){
            if(ans.find(mini)==ans.end()){
                return mini;
            }
            mini+=k;
        }
    }
};