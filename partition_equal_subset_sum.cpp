#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int n : nums) sum += n;
    if (sum & 1 != 0) return false;
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int n : nums) {
        for (int i = sum; i >= 1; i--) {
            if (i >= n) {
                dp[i] = dp[i] || dp[i - n];
            }
        }
    }
    return dp.back();
}

int main() {
    vector<int> nums = {1, 2, 5};
    cout << canPartition(nums) << endl;
    system("pause");
    return 0;
}