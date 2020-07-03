class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};