class Solution {
public:
    const int MOD = 1e9+7;
    long long power(long long a, long long b){
        long long res=1;
        while(b>0){
            if(b%2){
                res=(res*a)%MOD;
                b=b-1;
            }
            b=b/2;
            a=(a*a)%MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        return (power(5,even)*power(4,odd))%MOD;
    }
};