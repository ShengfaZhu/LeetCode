#include <iostream>
#include <vector>
using namespace std;

// using swap
int missingNumber(vector<int>& nums) {
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == -1 || nums[i] == i) continue;
        int tmp = nums[nums[i]];
        nums[nums[i]] = nums[i];
        nums[i] = tmp;
        i--;
    }
    for (int i = 0; i < nums.size(); i++) 
        if (nums[i] == -1) return i;
}

// using xor bit manipulation
int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans = ans ^ (i+1) ^ nums[i];
    return ans;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int n = missingNumber(nums);
    for (int i : nums)
        cout << i << "\t";
    system("pause");
    return 0;
}