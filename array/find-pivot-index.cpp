class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            total+=nums[i];
        }
        int sumL=0;
        for(int i=0; i<n; i++){
            total-=nums[i];
            if(total==sumL){
                return i;
            }
            sumL+=nums[i];
        }
        return -1;
    }
};