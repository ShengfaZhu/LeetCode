// 518. Coin Change 2
// another excellent dynamic program method
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < coins.size(); j++) {
        for (int i = 1; i <= amount; i++) {
            if (coins[j] <= i) {
                dp[i] = dp[i] + dp[i - coins[j]];
            }
        }
    }
    return dp[amount];
}