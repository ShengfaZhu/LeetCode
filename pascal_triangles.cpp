// In Pascal's triangle, each number is the sum of the 
// two numbers directly above it.
// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows < 1) return res;
    res.push_back(vector<int>(1,1));
    if (numRows == 1) return res;
    for (int row = 1; row < numRows; row++) {
        vector<int> tmp(1, 1);
        for (int i = 0; i < res[row - 1].size() - 1; i++)
            tmp.push_back(res[row - 1][i] + res[row - 1][i + 1]);
        tmp.push_back(1);
        res.push_back(tmp);
    }
    return res;
}