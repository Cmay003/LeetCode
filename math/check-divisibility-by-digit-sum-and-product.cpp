class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1, temp=n;
        while(temp>0){
            int digit=temp%10;
            temp/=10;
            sum+=digit;
            prod*=digit;
        }
        return (n%(sum+prod))==0;
    }
};