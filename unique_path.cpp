//  robot is located at the top-left corner of a m x n grid 
//  (marked 'Start' in the diagram below).
// The robot can only move either down or right at 
// any point in time. The robot is trying to reach the 
// bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// Example 1:
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right

#include <iostream>
#include <cmath>
using namespace std;

// backtrack solution
// int backtrack(int& m, int& n, int i, int j) {
//     if (i >= m || j >= n)
//         return 0;
//     if (i == m - 1 && j == n - 1)
//         return 1;
//     return backtrack(m, n, i + 1, j) + backtrack(m, n, i, j + 1);
// }

// C{m}{n}
long long pemutation(int m, int n) {
    int j = m, i = 1;
    long long res = 1;
    while(i <= n) {
        res = res * j / i;
        i++, j--;
    }
    return res;
}

int uniquePaths(int m, int n) {
    return pemutation(m + n - 2, min(n - 1, m - 1));
}

int main() {
    int m = 23, n = 12;
    cout << "unique path : " << uniquePaths(m, n) << endl;
    system("pause");
    return 0;
}