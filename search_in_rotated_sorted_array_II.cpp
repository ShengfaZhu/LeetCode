// Suppose an array sorted in ascending order is rotated 
// at some pivot unknown to you beforehand.
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
// You are given a target value to search. If found in the 
// array return true, otherwise return false.
// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    if (nums.empty())
        return false;
    // delete repeat element in both ends
    int low = 0, high = nums.size() - 1, mid;
    while (low != high && nums[low] == nums[high])
        high -= 1;
    if (low == high) {
        if (nums[low] == target)
            return true;
        else   
            return false;
    } 
    // search 
    while (low <= high) {
        cout << "low : " << low << "\t high : " << high << endl;
        mid = low + (high - low) / 2;
        if (nums[mid] == target) 
            return true;
        if (nums[low] <= nums[mid])// fisrt half in order
        {
            if (target < nums[low] || target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        else {// second half in order
            if (target < nums[mid] || target > nums[high]) high = mid - 1;
            else low = mid + 1;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    cout << search(nums, target) << endl;
    system("pause");
    return 0;
}