class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        int i = 0;
        for(char c:s){
            if(c>='A' && c<='Z'){
                c+=32;
            }
            ans.push_back(c);
        }
        return ans;
    }
};