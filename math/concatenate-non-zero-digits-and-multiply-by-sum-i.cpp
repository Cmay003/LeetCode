class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        string s = to_string(n);
        long long x;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='0'){
                x = (x*10)+(s[i]-48);
            }
            sum+=(s[i]-48);
        }
        return x*sum;
    }
};