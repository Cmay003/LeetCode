class Solution {
public:
    void helper(int k, int n, vector<vector<int>>&ans, vector<int> temp, int num){
        if(temp.size()==k){
            if(n==0) ans.push_back(temp);
            return;
        }
        if(num>9 || n<0) return;
        for(int i=num; i<10; i++){
            if(i>n) break;
            temp.push_back(i);
            helper(k, n-i, ans, temp, i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(k, n, ans, {}, 1);
        return ans;
    }
};