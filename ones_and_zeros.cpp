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
    // determine initial state
    int zeros = 0, ones = 0;
    for (int i = 0; i < strs.size(); i++) {
        if (count[i].second > 0)
            break;
        zeros += count[i].first;
        if (zeros <= m) dp[i+1][zeros][0] = i+1;
    }
    for (int i = 0; i < strs.size(); i++) {
        if (count[i].first > 0)
            break;
        ones += count[i].second;
        if (ones <= n) dp[i+1][0][ones] = i+1;
    }
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

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << findMaxForm(strs, m, n) << endl;;
    system("pause");
    return 0;
}