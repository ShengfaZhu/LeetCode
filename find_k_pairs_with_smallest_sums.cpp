#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    if (nums1.empty() || nums2.empty() || k <= 0) return res;
    auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
    for (int i = 0; i < nums1.size(); i++) min_heap.emplace(i, 0);
    while (k-- && !min_heap.empty()) {
        auto curr = min_heap.top();
        min_heap.pop();
        res.push_back(make_pair(nums1[curr.first], nums2[curr.second]));
        if (curr.second + 1 < nums2.size())
            min_heap.emplace(curr.first, curr.second + 1);
    }
    return res;
}

int main() {
    vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
    int k = 3;
    vector<pair<int, int>> res = kSmallestPairs(nums1, nums2, k);
    for (auto it = res.begin(); it != res.end(); it++) 
        cout << "[" << it->first << ", " << it->second << "], ";
    cout << endl;
    system("pause");
    return 0;
}