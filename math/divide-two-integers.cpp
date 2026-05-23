class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend<=0 && divisor>0) sign=false;
        if(dividend>=0 && divisor<0) sign=false;
        long long dd=abs((long long)dividend);
        long long ds=abs((long long)divisor);
        int ans=0;
        while(dd>=ds){
            int count=0;
            while(dd>=(ds<<(count+1))) count++;
            ans+=1<<count;
            dd=dd-(ds<<count);
        }
        if(ans==(1<<31) && sign) return INT_MAX;
        if(ans==(1<<31) && !sign) return INT_MIN;
        return (sign)?ans:(-1*ans);
    }
};