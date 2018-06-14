#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> maj_ele;
    int candidate1 = INT_MAX, candidate2 = INT_MAX, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count1 <= 0 && candidate2 != nums[i])
            candidate1 = nums[i];
        if (count2 <= 0 && (candidate1 != nums[i]))
            candidate2 = nums[i];   
        if (candidate1 == nums[i]) count1 += 2;
        else count1--;
        if (candidate2 == nums[i]) count2 += 2;
        else count2--;
    }
    // cout << candidate1 << "\t" << candidate2 << "\t";
    count1 = 0, count2 = 0;
    for (int i : nums) {
        if (i == candidate1) count1++;
        if (i == candidate2) count2++;
    }
    if (count1 > nums.size() / 3)  maj_ele.push_back(candidate1);
    if (candidate1 != candidate2 && count2 > nums.size() / 3)  maj_ele.push_back(candidate2);
    return maj_ele;
}

int main() {
    vector<int> nums = {10, 9, 9, 9, 10};
    vector<int> maj_ele = majorityElement(nums);
    for (int i : maj_ele) cout << i << "\t";
    system("pause");
    return 0;
}