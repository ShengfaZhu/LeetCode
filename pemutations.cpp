// Given a collection of distinct integers, 
// return all possible permutations.
// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <iostream>
#include <vector>
using namespace std;

// backtrack
void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int> sub_ans, vector<bool> is_exist) {
    if (sub_ans.size() == nums.size()) {
        res.push_back(sub_ans);
        return;
    }
    for (int i = 0; i < is_exist.size(); i++) {
        if (is_exist[i] == false) {
            sub_ans.push_back(nums[i]);
            is_exist[i] = true;
            backtrack(nums, res, sub_ans, is_exist);
            sub_ans.pop_back();
            is_exist[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub_ans;
    vector<bool> is_exist(nums.size(), false);
    backtrack(nums, res, sub_ans, is_exist);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for(int j = 0; j <res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}