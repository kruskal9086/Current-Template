int MatrixChainOrder(vector<int>& p) {
    int n = (int)p.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
 
    // L is chain length.
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
 
    return dp[1][n - 1];
}