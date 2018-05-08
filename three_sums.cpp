// Given an array nums of n integers, are there elements 
// a, b, c in nums such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;
    int i = 0;
    while(i < (int(nums.size()) - 2)) {
        if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
            i++;
            continue;
        }
            
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int temp_sum = nums[i] + nums[j] + nums[k];
            if (temp_sum == 0) {
                vector<int> trip(3, 0);
                trip[0] = nums[i], trip[1] = nums[j], trip[2] = nums[k];
                triplets.push_back(trip);
                j++;
                while( j < nums.size() - 1 && nums[j] == nums[j-1]) j++;
            }
            else {
                if (temp_sum < 0) j++;
                else k--;
            }
        }
        i++;
    }
    return triplets;
}

int main() {
    vector<int> nums= {0, 0, 0, 0};
    vector<vector<int>> triplets = threeSum(nums);
    for (int i  = 0; i < triplets.size(); i++) {
        for (int j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}