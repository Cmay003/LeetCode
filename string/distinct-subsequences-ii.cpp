class Solution {
public:
    static const int MOD = 1e9 + 7;

    int helper(string &s, int i, vector<int> &dp) {
        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long ans = 2LL * helper(s, i - 1, dp) % MOD;
        int j = i - 1;
        while (j >= 0 && s[j] != s[i])
            j--;

        if (j >= 0)
            ans = (ans - helper(s, j - 1, dp) + MOD) % MOD;

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return (helper(s, n - 1, dp)-1) % MOD;
    }
};