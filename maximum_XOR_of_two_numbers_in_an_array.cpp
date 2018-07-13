#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num & mask);
        }
        int t = res | (1 << i);
        for (int prefix : s) {
            if (s.count(t ^ prefix)) {
                res = t;
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums) << endl;
    system("pause");
    return 0;
}