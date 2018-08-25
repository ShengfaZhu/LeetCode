#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void findCore(const vector<int>& nums, vector<vector<int>>& res, vector<int> seq, int pos) {
    if (seq.size() > 1) res.push_back(seq);
    unordered_set<int> map;
    for (int i = pos; i < nums.size(); ++i) {
        if ((seq.empty() || seq.back() <= nums[i]) && map.find(nums[i]) == map.end()) {
            seq.push_back(nums[i]);
            findCore(nums, res, seq, i + 1);
            seq.pop_back();
            map.insert(nums[i]);
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) return res;
    vector<int> seq;
    findCore(nums, res, seq, 0);
    return res;
}

int main() {
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> res = findSubsequences(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (auto j : res[i]) cout << j << ", ";
        cout << "]" << endl;
    }
    system("pause");
    return 0;
}