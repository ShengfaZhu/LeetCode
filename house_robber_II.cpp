// 213. house robber
#include <iostream>
#include <vector>
using namespace std;

int rob_helper(vector<int>& nums, int low, int high) {
    if (low > high) return 0;
    if (low == high) return nums[low];
    vector<int> dp(high - low + 3, 0);
    dp[2] = nums[low];
    int i = 3;
    while (i < dp.size()) {
        if (dp[i - 2] > dp[i - 3]) dp[i] = dp[i - 2] + nums[i - 2 + low];
        else dp[i] = dp[i - 3] + nums[i - 2 + low];
        i++;
    }
    if (dp[dp.size() - 1] > dp[dp.size() - 2]) return dp[dp.size() - 1];
    else return dp[dp.size() - 2];
}

int rob(vector<int>& nums) {
    int r1 = rob_helper(nums, 0, nums.size() - 2);
    int r2 = rob_helper(nums, 1, nums.size() - 1);
    cout << r1 << "\t" << r2 << endl;
    return r1 > r2 ? r1 : r2;
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
    system("pause");
    return 0;
}