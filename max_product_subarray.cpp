// maximun product of subarray
// using Kadane algorothm
int maxProduct(vector<int>& nums) {
    int max_so_far = nums[0], max_end_here = nums[0], min_end_here = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(max_end_here, min_end_here);
        max_end_here = max(nums[i], max_end_here * nums[i]);
        min_end_here = min(nums[i], min_end_here * nums[i]);
        if (max_so_far < max_end_here) 
            max_so_far = max_end_here;
    }
    return max_so_far;
}