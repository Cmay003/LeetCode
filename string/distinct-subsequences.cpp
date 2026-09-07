class Solution {
public:
    int helper(string s, string t, int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;        
        if(s[i]==t[j]) return helper(s,t,i+1,j)+helper(s,t,i+1,j+1);
        return helper(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        // int n=s.size();
        // int m=t.size();
        return helper(s,t,0,0);
    }
};