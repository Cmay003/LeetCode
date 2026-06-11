class Solution {
public:
    int helper(int m, int n, int i, int j){
        if(i==m && j==n) return 1;
        int down=(i!=m)?helper(m,n,i+1,j):0;
        int right=(j!=n)?helper(m,n,i,j+1):0;
        return right+down;
    }
    int uniquePaths(int m, int n) {
        return helper(m,n,1,1);
    }
};