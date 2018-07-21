// 474. Ones and Zeroes
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    if (strs.empty()|| m < 0 || n < 0) return 0; 
    vector<pair<int, int>> count;
    for (string str : strs) {
        int zeros = 0, ones = 0;
        for (char c : str) {
            if (c == '0') zeros++;
            if (c == '1') ones++;
        }
        count.push_back(make_pair(zeros, ones));
    }
    vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
    // dynamic programming
    for (int i = 1; i <= strs.size(); i++) {
        for (int j = 0; j <= m; j++ ) {
            for (int k = 0; k <= n; k++) {
                if (count[i-1].first > j || count[i-1].second > k)
                    dp[i][j][k] = dp[i-1][j][k];
                else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count[i-1].first][k-count[i-1].second] + 1);
                }
            }
        }
    }
    return dp[strs.size()][m][n];
}

// much faster solution
int findMaxForm(vector<string>& strs, int m, int n) {
    if (strs.empty()|| m < 0 || n < 0) return 0; 
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // dynamic programming
    for (int i = 0; i < strs.size(); i++) {
        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            if (c == '1') ones++;
        }
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
            }
        }
    }
    return dp[m][n];
}

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << findMaxForm(strs, m, n) << endl;;
    system("pause");
    return 0;
}