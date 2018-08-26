// 494. Target Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// recursive way
// void backtrack(const vector<int>& nums, int& count, int target, int pos) {
//     if (pos == nums.size()) {
//         if (target == 0)
//             count++;
//         return;
//     }
//     backtrack(nums, count, target - nums[pos], pos + 1);
//     backtrack(nums, count, target + nums[pos], pos + 1);
// }

// int findTargetSumWays(vector<int>& nums, int S) {
//     int count = 0;
//     backtrack(nums, count, S, 0);
//     return count;
// }

// dynamic programming
int findTargetSumWays(vector<int>& nums, int S) {
    if (nums.empty()) return 0;
    unordered_map<int, int> count;
    for (int n : nums) {
        if (count.empty()) {
            count[n] = 1;
            count[-n] = 1;
            if (n == 0) count[0] = 2;
        }
        else {
            unordered_map<int, int> new_count;
            for (auto it = count.begin(); it != count.end(); ++it) {
                if (new_count.find((it->first + n)) == new_count.end())
                    new_count[it->first + n] = count[it->first];
                else new_count[it->first + n] = count[it->first] + new_count[it->first + n];    
                if (new_count.find((it->first - n)) == new_count.end())
                    new_count[it->first - n] = count[it->first];
                else new_count[it->first - n] = count[it->first] + new_count[it->first - n];   
            }
            count = new_count;
        }
    }
    if (count.find(S) == count.end()) return 0;
    else return count[S];
}

int main() {
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target = 1;
    cout << findTargetSumWays(nums, target) << endl;
    system("pause");
    return 0;
}