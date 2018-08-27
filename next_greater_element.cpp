// 503. Next Greater Element II
vector<int> nextGreaterElements(vector<int>& nums) {    
    vector<int> next(nums.size(), -1);
    if (nums.empty()) return next;
    stack<int> st;
    int sz = nums.size();
    for (int i = 0; i < 2 * sz; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i % sz]) {
            next[st.top()] = nums[i % sz];
            st.pop();
        }
        st.push(i % sz);
    }
    return next;
}