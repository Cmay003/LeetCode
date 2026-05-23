class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;
        unordered_set<int> sums;
        int sum=0, prev=0;
        for(int i=0; i<n; i++){
            sum=(sum+nums[i])%k;
            if(sums.find(sum)!=sums.end()) return true;
            sums.insert(prev);
            prev=sum;            
        }
        return false;
    }
};