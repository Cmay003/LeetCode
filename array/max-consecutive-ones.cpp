class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==0){
                count=0;
            }
            else{
                count+=1;
                maxi=max(count, maxi);
            }
        }
        return maxi;
    }
};