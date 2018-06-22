#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int numSquares(int n) {
    if (n <= 0) return 0;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp.back();
}

int main() {
    int n = 24;
    cout << numSquares(n) << endl;
    system("pause");
    return 0;
}