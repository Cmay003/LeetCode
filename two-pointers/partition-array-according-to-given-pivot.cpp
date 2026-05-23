class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> left;
        vector<int> middle;
        vector<int> right;
        for(int i=0; i<n; i++){
           if(nums[i]<pivot) left.push_back(nums[i]);
           if(nums[i]==pivot) middle.push_back(nums[i]);
           if(nums[i]>pivot) right.push_back(nums[i]);
        }
        left.insert(left.end(), middle.begin(), middle.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};