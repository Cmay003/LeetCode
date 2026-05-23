class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(original==nums[i]){
                original*=2;
                i=0;
            }
            else i++;
        }
        return original;
    }
};