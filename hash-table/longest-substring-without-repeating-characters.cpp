class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0, j=0, ans=0;
        unordered_map<char, int> mpp;
        while(j<n){
            if(mpp.count(s[j]) && mpp[s[j]]>=i){
                i=mpp[s[j]]+1;
            }
            mpp[s[j]]=j;
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};