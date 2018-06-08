// 198. house robber
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int i = 2;
    if (i < nums.size()) nums[i] += nums[0];
    i++;
    while (i < nums.size()) {
        if (nums[i - 2] > nums[i - 3]) nums[i] += nums[i - 2];
        else nums[i] += nums[i - 3];
        i++;
    }
    if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums[nums.size() - 1];
    else return nums[nums.size() - 2];
}