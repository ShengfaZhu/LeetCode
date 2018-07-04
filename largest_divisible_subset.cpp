// 368. Largest Divisible Subset
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 0) return nums;
    sort(nums.begin(), nums.end());
    vector<int> count(sz, 1), pre(sz, -1);
    int max = 0, index = -1;
    for (int i = 0; i < sz; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                if (count[j] + 1 > count[i]) {
                    count[i] = count[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (max < count[i]) {
            max = count[i];
            index = i;
        }
    }
    vector<int> ans;
    while (index != -1) {
        ans.push_back(nums[index]);
        index = pre[index];
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 4, 6, 12};
    vector<int> ans = largestDivisibleSubset(nums);
    for (int n : ans) cout << n << endl;
    system("pause");
    return 0;
}