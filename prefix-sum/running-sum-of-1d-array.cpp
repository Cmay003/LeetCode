class Solution {
public:
    // long sum(vector<int> &arr, long index){
    //     long sum=0;
    //     for(long i=0; i<=index; i++){
    //         sum+=arr[i];
    //     }
    //     return sum;
    // }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};