// Given a collection of candidate numbers (candidates) 
// and a target number (target), find all unique combinations 
// in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, 
    vector<vector<int>>& res, vector<int> nums, vector<int>& count, int k) {
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
        if (nums[z] + 1 <= count[z]) {
            nums[z]++;
            for (int& m : nums)
                cout << m << "\t";
            cout << endl;
            backtrack(candidates, target, res, nums, count, z);
            nums[z]--;            
        }
        z++;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if (candidates.empty())
        return res;
    sort(candidates.begin(), candidates.end());
    vector<int> count(1, 1), nums_no_repeat(1, candidates[0]);
    int i = 1, j = 0;
    while(i < candidates.size()) {
        if (candidates[i] == candidates[i - 1])
            count[j]++;
        else {
            nums_no_repeat.push_back(candidates[i]);
            count.push_back(1);
            j++;
        }
        i++;
    }
    vector<int> nums(nums_no_repeat.size(), 0);
    backtrack(nums_no_repeat, target, res, nums, count, 0);
    return res;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5}; 
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target); 
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
