// 473. Matchsticks to Square
bool makesquare(vector<int>& nums) {
    if (nums.size() < 4) return false;
    int sum = 0;
    for (int n : nums) sum += n;
    if (sum % 4 != 0) return false;
    int edge_len = sum / 4;
    vector<int> sums(4, 0);
    auto cmp = [](int x, int y) {return x > y;};
    sort(nums.begin(), nums.end(), cmp);
    return dfs(nums, sums, 0, edge_len);
    
}

bool dfs(vector<int>& nums, vector<int> sum, int index, int target) {
    if (index == nums.size()) {
        if (sum[0] == target && sum[1] == target && sum[2] == target)
            return true;
        return false;
    }
    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] + nums[index] > target) continue;
        sum[i] += nums[index];
        if (dfs(nums, sum, index + 1, target)) return true;
        sum[i] -= nums[index];
    }
    return false;
}