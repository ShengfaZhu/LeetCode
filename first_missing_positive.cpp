#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    // put each number at right place
    for (int i = 0; i < nums.size(); ++i) {
        while (nums.at(i) > 0 && nums.at(i) - 1 < nums.size() && nums.at(nums.at(i) - 1) != nums.at(i)) {
            swap(nums.at(i), nums.at(nums.at(i) - 1));
        }
    }
    // find first place missing right number
    for (int i = 0; i < nums.size(); ++i) {
        if (nums.at(i) != i + 1) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main()
{
    vector<int> nums = {1, 2, 0};
    firstMissingPositive(nums);
    for (int& i : nums) {
        cout << i << "\t";
    }
    system("pause");
    return 0;
}