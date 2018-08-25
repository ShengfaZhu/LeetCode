#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// recursive-way
// int maxFetch(const vector<int>& nums, int sum, int pre, int last) {
//     assert(pre >= 0 && pre <= last && last < nums.size());
//     if (pre == last) return nums[pre];
//     int fetch_pre = sum - maxFetch(nums, sum - nums[pre], pre + 1, last);
//     int fetch_last = sum - maxFetch(nums, sum - nums[last], pre, last - 1);
//     return max(fetch_pre, fetch_last);
// }

// bool PredictTheWinner(vector<int>& nums) {
//     if (nums.empty()) return true;
//     int sum = 0;
//     for (auto i : nums) sum += i;
//     int max_fetch = maxFetch(nums, sum, 0, nums.size() - 1);
//     return max_fetch >= (sum - max_fetch);
// }

// dynamic program way
bool PredictTheWinner(vector<int>& nums) {
    if (nums.empty()) return true;
    int sz = nums.size();
    vector<int> sum(sz, nums[0]);
    for (int i = 1; i < sz; ++i) sum[i] = sum[i-1] + nums[i];
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    for (int i = 0; i < sz; ++i) dp[i][i] = nums[i];
    for (int k = 1; k <= sz - 1; ++k) {
        for (int i = 0; i <= sz - 1 - k; ++i) {
            int j = i + k;
            int sum_ij = sum[j] - (i > 0 ? sum[i-1] : 0);
            dp[i][j] = sum_ij - min(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout << dp[0][sz - 1] << endl;
    return dp[0][sz-1] >= (sum[sz-1] - dp[0][sz-1]);
}

int main() {
    vector<int> nums = {1, 5, 233, 7};
    cout << PredictTheWinner(nums) << endl;
    system("pause");
    return 0;
}