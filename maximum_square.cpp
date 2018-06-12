// 221. Maximal Square
// using dynamic programming
int min3(int a, int b, int c) {
    return min(min(a, b), c);
}
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int num_row = matrix.size(), num_col = matrix[0].size(), max_area = 0;
    vector<vector<int>> dp(num_row + 1, vector<int>(num_col + 1, 0));
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            if (matrix[i][j] == '1') {
                dp[i+1][j+1] = min3(dp[i][j], dp[i][j+1], dp[i+1][j]) + 1;
                max_area = max(dp[i+1][j+1], max_area);
            }
        }
    }
    return max_area * max_area;
}