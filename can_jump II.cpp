int jump(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int current_max = 0, next_max= 0, i = 0, level = 0;
    while (i < nums.size()) {
        level++;
        for (; i <= current_max; ++i) {
            next_max = max(next_max, nums[i] + i);
            if (next_max + 1 >= nums.size()) {
                return level;
            }
        }
        current_max = next_max;
        next_max = 0;
    }
    return -1;
}