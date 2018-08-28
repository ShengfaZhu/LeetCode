// 516. Longest Palindromic Subsequence
// dynamic programming method`
int longestPalindromeSubseq(string s) {
    if (s.empty()) return 0;
    int sz = s.size();
    vector<vector<int> > dp(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; ++i) dp[i][i] = 1;
    for (int k = 1; k <= sz - 1; ++k) {
        for (int row = 0; row <= sz - 1 - k; ++row) {
            int col = row + k;
            if (s[row] == s[col]) {
                dp[row][col] = dp[row+1][col-1] + 2;
            }
            else {
                dp[row][col] = max(dp[row+1][col], dp[row][col-1]);
            }
        }
    }
    return dp[0][sz-1];
}