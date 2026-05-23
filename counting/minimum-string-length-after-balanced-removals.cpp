class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.size();
        int cnta=0, cntb=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a') cnta++;
            else cntb++;
        }
        if(cnta>cntb) return cnta-cntb;
        else return cntb-cnta;
    }
};