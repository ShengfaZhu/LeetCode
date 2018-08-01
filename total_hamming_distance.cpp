// Total Hamming Distance
int totalHammingDistance(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < 32; i++) {
        int bitCount = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] & (1 << i)) bitCount++;
        }            
        sum += bitCount * (nums.size() - bitCount);
    }
    return sum;
}