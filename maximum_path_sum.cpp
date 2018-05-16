// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes 
// the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.
// Example:
// Input:
// {
//   {1,3,1},
//   {1,5,1},
//   {4,2,1}
// }
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][1] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    vector<vector<int>> grid = {
    {1,3,1},
    {1,5,1},
    {4,2,1}};
    cout << minPathSum(grid) << endl;
    system("pause");
    return 0;
}