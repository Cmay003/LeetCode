class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[nums.size()-1];
        vector<int> ans;
        for(int i=mini; i<maxi; i++){
            auto it = find(nums.begin(), nums.end(), i);
            if(it==nums.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};