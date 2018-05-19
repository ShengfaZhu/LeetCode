// Given a collection of integers that might contain duplicates, 
// nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
// Example:
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> local, int k) {
    if (k >= 0) {
        local.push_back(nums[k]);   
    }
    res.push_back(local);
    for (int i = k + 1; i < nums.size(); i++) {
        if (i > k + 1 && nums[i] == nums[i - 1]) continue;
        backtrack(nums, res, local, i);
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> local;
    backtrack(nums, res, local, -1);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}