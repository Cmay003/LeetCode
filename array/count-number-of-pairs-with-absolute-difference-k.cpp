class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count=0;
        for(auto i : nums){
            count+=mpp[i+k];
            count+=mpp[i-k];
            mpp[i]++;
        }
        return count;
    }
};