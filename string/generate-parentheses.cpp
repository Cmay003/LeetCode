class Solution {
public:
    void helper(int n, vector<string>&ans, string str,int left, int right){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(left<n){ 
            helper(n, ans, str+'(',left+1, right);
        }
        if(left>right) helper(n, ans, str+')',left, right+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "", 0, 0);
        return ans;
    }
};