// Suppose an array sorted in ascending order is rotated 
// at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. 
// If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

#include <iostream>
#include <vector>
using namespace std;

int search_sorted(vector<int>& nums, int target, int low, int high) {
    if (low < 0 || high >= nums.size())
        return -1;
    while(low <= high) {
        if (nums[low] == target)
            return low;
        if (nums[high] == target)
            return high;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target) 
            low = mid+1;
        else
            high = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    if (nums.empty())
        return -1;
    // detect rotate pivot
    int low = 0;
    int high = nums.size() - 1;
    if (nums[low] <= nums[high])// no rotated
        return search_sorted(nums, target, low, high);
    // rotated
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[low] < nums[mid]) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << "low : " << nums[low] << endl;
    cout << "high : " << nums[high] << endl;
    // search for target in first segement
    int ind = search_sorted(nums, target, 0, high);
    if (ind != -1)
        return ind;
    ind = search_sorted(nums, target, high + 1, nums.size() - 1);
    return ind;
}

int main() {
    vector<int> nums = {1};
    int target = 1;
    cout << search(nums, target) << endl;
    system("pause");
    return 0;
}