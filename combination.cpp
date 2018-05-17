// Given two integers n and k, return all possible 
// combinations of k numbers out of 1 ... n.
// Example:
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>>& res, vector<int> local, 
    int i, int n, int k) {
    if (local.size() == k) {
        res.push_back(local);
        return;
    }
    for (int j = i + 1; j <= n; j++) {
        local.push_back(j);
        backtrack(res, local, j, n, k);
        local.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<int > local;
    vector<vector<int>> res;
    backtrack(res, local, 0, n, k);
    return res;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> res = combine(n, k);
    for (int i = 0; i <res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}