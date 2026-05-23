class Solution {
public:
    int countCommas(int n) {
        int ans=0, temp=1000;
        while(temp<=n){
            ans+=n-temp+1;
            temp*=1000;
        }
        return ans;
    }
};