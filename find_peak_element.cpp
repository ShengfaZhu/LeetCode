// A peak element is an element that is greater than its neighbors.
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak 
// element and return its index.
// The array may contain multiple peaks, in that case return the 
// index to any one of the peaks is fine.
// You may imagine that nums[-1] = nums[n] = -∞.
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid+1])
            high = mid;
        else
            low = mid + 1;
    }
    return high;
}