class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            sum+=(s[i]-'a'+1);
        }
        int lsum = 0;
        for(int j=0; j<s.size()-1; j++){
            lsum+=(s[j]-'a'+1);
            int rsum = sum-lsum;
            if(lsum == rsum) return true;
        }
        return false;
    }
};