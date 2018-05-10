// Given an array nums of n integers and an integer target, 
// are there elements a, b, c, and d in nums such that 
// a + b + c + d = target? Find all unique quadruplets 
// in the array which gives the sum of target.
// Note:
// The solution set must not contain duplicate quadruplets.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// double pointer method solve k-sum problems
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if (nums.size() < 4) 
        return ans;
    sort(nums.begin(), nums.end());
    int i = 0;
    while(i < nums.size() - 3) {
        // avoid repeating
        if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
            i++;
            continue;
        }
        // prune
        if (nums[i] + nums[nums.size()-3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) {
            i++;
            continue;
        }            
        int j = i + 1;
        while (j < nums.size() - 2) {
            // avoid repeating
            if (j >= i + 2 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            //prune
            if (nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) {
                j++;
                continue;
            }             
            int k = j + 1, m = nums.size() - 1;
            while(k < m) {
                int tmp = nums[i] + nums[j] + nums[k] + nums[m];
                if (tmp == target) {
                    vector<int> a;
                    a.push_back(nums[i]), a.push_back(nums[j]), 
                    a.push_back(nums[k]), a.push_back(nums[m]);
                    ans.push_back(a);
                    while(nums[k] == nums[k + 1])
                        k++;
                    while(nums[m] == nums[m - 1])
                        m--;
                    k++;
                    m--;
                }
                else {
                    if (tmp < target) k++;
                    else m--;
                }
            }
            j++;
        }
        i++;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}