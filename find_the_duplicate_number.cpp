// 287. Find the Duplicate Number
// Floyd's Tortoise and Hare Algorithm
int findDuplicate(vector<int>& nums) {
    // detect cycle
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // find entrance of cycle
    int ptr1 = 0, ptr2 = slow;
    while (ptr1 != ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return ptr1;      
}