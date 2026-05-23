class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        bool check=false;
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                if(!check) check=true;
                else{
                    if(count<k) return false;
                }
                count=0;
            }
            else count++;
        }
        return true;
    }
};