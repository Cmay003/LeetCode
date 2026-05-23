class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for(int i=0; i<nums.size(); i++){
            int idx = index[i];
            int num = nums[i];
            target.insert(target.begin()+idx,num);
        }
        return target;
    }
};