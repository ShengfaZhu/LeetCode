// Given a set of distinct integers, nums, return all 
// possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
// Example:
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int> local, int k) {
    res.push_back(local);
    if (k >= nums.size())
        return;
    for (int i = k; i < nums.size(); i++) {
        local.push_back(nums[i]);
        backtrack(res, nums, local, i + 1);
        local.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> local;
    backtrack(res, nums, local, 0);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}