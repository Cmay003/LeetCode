class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int i=nums.size()-1;
        vector<int> ans(nums.begin(), nums.end());
        while(i>=0){
            ans.push_back(nums[i]);
            i--;
        }
        return ans;
    }
};