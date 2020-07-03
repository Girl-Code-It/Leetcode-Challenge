class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &arr)
    {
        int r = arr.size();
        if (!r)
            return 0;
        int c = arr[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

        //dp[i][j] = minmimum power required to go from arr[i][j] to arr[r-1][c-1]
        dp[r - 1][c - 1] = arr[r - 1][c - 1] >= 0 ? 1 : abs(arr[r - 1][c - 1] - 1);
        //last col base case
        for (int i = r - 2; i >= 0; i--)
        {
            if (dp[i + 1][c - 1] <= arr[i][c - 1])
                dp[i][c - 1] = 1;
            else
                dp[i][c - 1] = dp[i + 1][c - 1] - arr[i][c - 1];
        }
        //last row base case
        for (int i = c - 2; i >= 0; i--)
        {
            if (dp[r - 1][i + 1] <= arr[r - 1][i])
                dp[r - 1][i] = 1;
            else
                dp[r - 1][i] = dp[r - 1][i + 1] - arr[r - 1][i];
        }
        for (int i = r - 2; i >= 0; i--)
        {
            for (int j = c - 2; j >= 0; j--)
            {
                int up = max(1, dp[i + 1][j] - arr[i][j]);
                int left = max(1, dp[i][j + 1] - arr[i][j]);
                dp[i][j] = min(up, left);
            }
        }
        return dp[0][0];
    }
};