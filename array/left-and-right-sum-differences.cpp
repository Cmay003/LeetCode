class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer;
        int ls=0;
        int rs=0;
        for(int i=0; i<nums.size(); i++){
            rs+=nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            rs-=nums[i];
            answer.push_back(abs(ls-rs));
            ls+=nums[i];
        }
        return answer;
    }
};