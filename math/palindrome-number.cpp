class Solution {
public:
    bool isPalindrome(int x) {
        long dig, pal=0;
        long n=x;
        while(n>0){
            dig=n%10;
            n=n/10;
            pal=pal*10+dig;
        }
        if(x==pal) return true;
        else return false;
    }
};