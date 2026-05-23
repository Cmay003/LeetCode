class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0, temp=1000;
        while(temp<=n){
            ans+=n-temp+1;
            temp*=1000;
        }
        return ans;
    }
};