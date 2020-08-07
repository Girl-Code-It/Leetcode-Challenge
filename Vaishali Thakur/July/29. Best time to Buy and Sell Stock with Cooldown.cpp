class Solution {
public:
	int maxProfit(vector<int>& prices){
        int n = prices.size();
		if(n <= 1) 
            return 0;
		
        if(n == 2){
            if(prices[1] > prices[0])
                return (prices[1] - prices[0]);
            else
                return 0;
        }
        
        int dp[n][2];
        // dp[i][0] - no stock on day i: sold it or leave it
        // dp[i][1] - stock on day i: bought it or leave it
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
        
        for(int i = 2; i < n; i++){
            // depends on last bought stock
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);  
            // depends on last sold stock i.e. (i - 2) coz (i - 1) will be cool down day
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        
        return dp[n - 1][0];
	}
};
