class Solution {
public:
    int helper(string s, int idx, long long res, int sign){
        if(!isdigit(s[idx])) return sign*res;
        res=res*10+(s[idx]-'0');
        if(sign*res>INT_MAX) return INT_MAX;
        if(sign*res<INT_MIN) return INT_MIN;
        return helper(s, idx+1, res, sign);
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        int sign=1;
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign=-1;
            i++;
        }
        long long ans=0;
        return helper(s, i, ans, sign);
    }
};