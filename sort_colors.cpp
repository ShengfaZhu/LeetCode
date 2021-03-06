// Given an array with n objects colored red, white or blue, 
// sort them in-place so that objects of the same color are adjacent, 
// with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, 
// white, and blue respectively.
// Note: You are not suppose to use the library's sort function for this problem.
#include <iostream>
#include <vector>
using namespace std;

// counting sort
/* void sortColors(vector<int>& nums) {
    if (nums.empty())
        return;
    vector<int> count(3, 0);// 0, 1, 2
    // counting
    for (int& i : nums)
        count[i]++;
    // sort, overwriting nums
    int j = 0;
    for (int& i : nums) {
        while (count[j] == 0 && j < count.size())
            j++;
        if (count[j] > 0) {
            i = j;
            count[j]--;
        }
    }
} */

// 3-way partition
void sortColors(vector<int>& nums) {
    if (nums.empty()) return;
    int i = 0, low = 0, high = nums.size() - 1;
    while (i <= high) {
        if (nums[i] == 1) i++;
        else if (nums[i] == 0) swap(nums[i++], nums[low++]);
        else swap(nums[i], nums[high--]);
    }
}

int main() {
    vector<int> num = {1, 2, 1, 0, 0, 2, 1, 1};
    sortColors(num);
    for (int& i : num)
        cout << i << "\t";
    system("pause");
    return 0;
}