// 209. Minimum Size Subarray Sum
int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0, j = 0, tmp_sum = nums[0], min_len = INT_MAX;
    while (j < nums.size()) {
        if (tmp_sum >= s) {
            min_len = min(min_len, j - i + 1);
            if (i == j) return 1;
            tmp_sum = tmp_sum - nums[i];
            i++;
        }
        else {
            j++;
            tmp_sum = tmp_sum + nums[j];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}