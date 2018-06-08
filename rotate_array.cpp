// 189. Given an array, rotate the array to the right by k steps, 
// where k is non-negative.
void rotate(vector<int>& nums, int k) {
    int count = 0, start = 0;
    while (count < nums.size()) {
        int i = (start + k) % nums.size();
        int n = nums[start];
        while (i != start) {
            int tmp = nums[i];
            nums[i] = n;
            n = tmp;
            i = (i + k) % nums.size();
            count++;
        }
        nums[start] = n;
        count++;
        start++;
    }
}