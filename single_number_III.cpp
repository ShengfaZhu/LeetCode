#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int n = 0, n1 = 0, n2 = 0;
    for (int i : nums)
        n = n ^ i;
    int dect = 1;
    while ((dect & n) == 0) 
        dect = dect << 1;
    for (int i : nums) {
        if ((i & dect) == 0)
            n1 = n1 ^ i;
        else
            n2 = n2 ^ i;
    }
    vector<int> ans = {n1, n2};
    return ans;
}

int main() {
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = singleNumber(nums);
    for (int i : ans) cout << i << "\t";
    system("pause");
    return 0;
}