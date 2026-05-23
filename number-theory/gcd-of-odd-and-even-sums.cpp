class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = n*(n+1);
        int sumOdd = n*n;
        while(sumEven!=0){
            int temp=sumEven;
            sumEven=sumOdd%sumEven;
            sumOdd=temp;
        }
        return sumOdd;
    }
};