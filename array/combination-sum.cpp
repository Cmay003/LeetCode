class Solution {
public:
    void helper(vector<int>&candidates, int target, vector<vector<int>>&ans, int idx, vector<int>&temp){
        if(idx>=candidates.size() || target<=0){
            if(target==0) ans.push_back(temp);
            return; 
        }
        temp.push_back(candidates[idx]);
        helper(candidates, target-candidates[idx], ans, idx, temp);
        temp.pop_back();
        helper(candidates, target, ans, idx+1, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, ans, 0, temp);
        return ans;
    }
};