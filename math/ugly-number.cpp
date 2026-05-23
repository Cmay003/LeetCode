class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        long long x=n;
        while(x%2==0 || x%3==0 || x%5==0){
            if(x%2==0) x/=2;
            else if(x%3==0) x/=3;
            else x/=5;
        }
        return (x==1);
    }
};