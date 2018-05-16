// DescriptionHintsSubmissionsDiscussSolution
// A robot is located at the top-left corner of a m x n grid 
// (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid 
// (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. 
// How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size() , n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    dp[1][0] = 1;
    for(int i = 1 ; i <= m ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            if(!obstacleGrid[i-1][j-1])
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
    return dp[m][n];
}

int main() {
vector<vector<int>> grid = { {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}};
    cout << uniquePathsWithObstacles(grid) << endl;
    system("pause");
    return 0;
}