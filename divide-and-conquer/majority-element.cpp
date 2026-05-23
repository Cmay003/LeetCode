class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int elem;
        int sum=0;
        for(int i=0; i<n; i++){
            if(sum==0){
                sum=1;
                elem=nums[i];
            }
            else if(nums[i]==elem){
                sum++;
            }
            else sum--;
        }
        sum=0;
        for(int i=0; i<n; i++){
            if(nums[i]==elem){
                sum++;
            }
        }
        if(sum>n/2){
            return elem;
        }
        else return -1;
    }
};