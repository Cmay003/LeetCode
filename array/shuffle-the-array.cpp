class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0; i<nums.size(); i++){
            if(i<n){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        int idx1=0, idx2=0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                nums[i] = arr1[idx1++];
            }
            else{
                nums[i] = arr2[idx2++];
            }
        }
        return nums;
    }
};