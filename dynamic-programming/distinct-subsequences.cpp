class Solution {
public:
    // int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    //     if(j==t.size()) return 1;
    //     if(i==s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]) return dp[i][j]=helper(s,t,i+1,j,dp)+helper(s,t,i+1,j+1,dp);
    //     return dp[i][j]=helper(s,t,i+1,j,dp);
    // }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(t.size()==0) return 1;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=m;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][m]=1;        
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                if(s[i]==t[j]) dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
                else dp[i][j]=dp[i+1][j];
            }
        }
        return dp[0][0];
        // return helper(s,t,0,0,dp);
    }
};