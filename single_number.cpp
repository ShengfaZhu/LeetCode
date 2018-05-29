// Given a non-empty array of integers, every element appears twice 
// except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you 
// implement it without using extra memory?
// Example 1:
// Input: [2,2,1]
// Output: 1
// Example 2:
// Input: [4,1,2,1,2]
// Output: 4
//  A xor A = 0, 异或操作满足交换律和结合律 
int singleNumber(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)
        nums[0] = nums[i] ^ nums[0];
    return nums[0];
}