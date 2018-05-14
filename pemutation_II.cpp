// Given a collection of numbers that might contain duplicates, 
// return all possible unique permutations.
// Example:
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// backtrack
void backtrack(vector<int> nums, int i, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int k = i; k < nums.size(); k++) {
        if (i != k && nums[i] == nums[k]) continue;
        swap(nums[i], nums[k]);
        backtrack(nums, i + 1, res);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    backtrack(nums, 0, res);
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permuteUnique(nums);
    for (int i = 0; i < res.size(); i++) {
        for(int j = 0; j <res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}