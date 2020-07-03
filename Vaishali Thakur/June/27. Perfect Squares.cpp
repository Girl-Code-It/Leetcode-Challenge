class Solution {
public:
    int numSquares(int n) {
        if(n < 4)
            return n;
        
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1; 
        dp[2] = 2; 
        dp[3] = 3;
        for(int i = 1; i <= n; i++){
            dp[i] = i;
            for(int j = 1; j <= sqrt(i); j++){
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }
        
        return dp[n];
    }
};