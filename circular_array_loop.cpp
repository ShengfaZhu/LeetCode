// 457. Circular Array Loop
int move(int curr, vector<int>& nums) {
    return (nums[curr] > 0) ? (curr + nums[curr]) % nums.size() : nums.size() + ((curr + nums[curr]) % nums.size());
}

bool circularArrayLoop(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) continue;
        int j = i, k = move(i, nums);
        while (nums[k] * nums[i] > 0 && nums[move(k, nums)] * nums[i] > 0) {
            if (j == k) {
                if (j == move(j, nums))
                    break;
                return true;
            }
            j = move(j, nums);
            k = move(move(k, nums), nums);
        }
        j = i;
        int val = nums[j];
        while (nums[j] * val > 0) {
            int next = move(j, nums);
            nums[j] = 0;
            j = next;
        }
    }
    return false;
}