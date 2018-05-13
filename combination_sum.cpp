// Given a set of candidate numbers (candidates) (without duplicates) 
// and a target number (target), find all unique combinations 
// in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates 
// unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [  [7],
//   [2,2,3]]
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, 
    vector<vector<int>>& res, vector<int> nums, int k) {
    int sum = 0;
    for (int i = 0; i < candidates.size(); i++) {
        sum += candidates[i] * nums[i];
    }
    if (sum == target) {
        vector<int> ans;
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = 0; j < nums[i]; j++) {
                ans.push_back(candidates[i]);
            }
        }
        res.push_back(ans);
        return;
    }
    if (sum > target) {
        return;
    }
    int z = k;
    while(z < nums.size()) {
        nums[z]++;
        backtrack(candidates, target, res, nums, z);
        nums[z]--;
        z++;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> nums(candidates.size(), 0);
    backtrack(candidates, target, res, nums, 0);
    return res;
}

int main()
{
    vector<int> candidates = {2, 3, 5}; 
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target); 
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
