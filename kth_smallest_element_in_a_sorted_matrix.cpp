#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto cmp = [&matrix](pair<int, int> a, pair<int, int> b) {
        return matrix[a.first][a.second] > matrix[b.first][b.second];};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
    int sz = matrix.size();
    for (int n = 0; n < sz; n++) min_heap.emplace(make_pair(0, n));
    while (--k && !min_heap.empty()) {
        auto curr = min_heap.top();
        min_heap.pop();
        if (curr.first + 1 < sz) min_heap.emplace(make_pair(curr.first + 1, curr.second));
    }
    auto curr = min_heap.top();
    return matrix[curr.first][curr.second];
}

int main() {
    vector<vector<int>> matrix = {{1,  5,  9},{10, 11, 13},{12, 13, 15}};
    int k = 6;
    cout << kthSmallest(matrix, k) << endl;
    system("pause");
    return 0;
}