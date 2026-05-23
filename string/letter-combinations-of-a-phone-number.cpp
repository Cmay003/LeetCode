class Solution {
public:
    void helper(string digits, vector<string>&ans, vector<string>&characters, string temp, int idx){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        int digit=digits[idx]-'0';
        for(int i=0; i<characters[digit].size(); i++){
            helper(digits, ans, characters, temp+characters[digit][i], idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> characters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits, ans, characters, "", 0);
        return ans;
    }
};