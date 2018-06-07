// Moore voting algorithm
int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for (int i : nums) {
        if (count == 0)
            candidate = i;
        count += (i == candidate ? 1 : -1);
    }
    return candidate;
}