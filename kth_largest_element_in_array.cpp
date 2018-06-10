// 215. Kth Largest Element in an Array
int partition(vector<int>& nums, int low, int high) {
    // 任取一元素与首元素交换，后续以首元素作为基准
    int r = low + rand() % (high - low + 1);
    int tmp = nums[low];
    nums[low] = nums[r];
    nums[r] = tmp;
    int pivot = nums[low];
    // 由向量两端向中部扫描
    while (low < high) {
        while (low < high && pivot <= nums[high])
            high--;
        nums[low] = nums[high];
        while (low < high && pivot >= nums[low])
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    int low = 0, high = nums.size() - 1;
    while (true) {
        int m = partition(nums, low, high);
        if (m < k) low = m + 1;
        else if (m > k) high = m - 1;
        else return nums[m];
    }
}