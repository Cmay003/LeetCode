class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out="";
        int len = strs.size();
        sort(strs.begin(),strs.end());
        string left=strs[0];
        string right=strs[len-1];
        for(int i=0; i<min(left.size(),right.size()); i++){
            if(left[i]!=right[i]){
                return out;
            }
            out = out + left[i];
        }
        return out;
    }
};