// 376. Wiggle Subsequence
int wiggleMaxLength(vector<int>& nums) {
    int sz = nums.size();
    if (sz < 2) return nums.size();
    vector<int> pos_count(sz, 1), neg_count(sz, 1);
    for (int i = 1; i < sz; i++) {
        if ((pos_count[i-1] % 2 == 1 && nums[i] > nums[i-1]) || 
            (pos_count[i-1] % 2 == 0 && nums[i] < nums[i-1]))  {
            pos_count[i] = pos_count[i-1] + 1;      
        }
        else
            pos_count[i] = pos_count[i-1];
        if ((neg_count[i-1] % 2 == 1 && nums[i] < nums[i-1]) || 
            (neg_count[i-1] % 2 == 0 && nums[i] > nums[i-1]))  {
            neg_count[i] = neg_count[i-1] + 1; 
        }
        else neg_count[i] = neg_count[i-1];
    }
    return max(pos_count.back(), neg_count.back());
}