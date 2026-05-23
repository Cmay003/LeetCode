class Solution {
public:
    void helper(int n, vector<string>&ans, int prev, string str){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        helper(n, ans, 1, str+'1');
        if(prev!=0) helper(n, ans, 0, str+'0');
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, ans, -1, "");
        return ans;
    }
};