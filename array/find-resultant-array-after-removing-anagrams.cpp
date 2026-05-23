class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string a = "";
        for(int i=0; i<words.size(); i++){
            string b = words[i];
            sort(b.begin(), b.end());
            if(a!=b){
                ans.push_back(words[i]);
                a = b;
            }
        }
        return ans;
    }
};