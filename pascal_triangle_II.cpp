// In Pascal's triangle, each number is the sum of the 
// two numbers directly above it.
// Example:
// Input: 3
// Output: [1,3,3,1]
// Follow up:
// Could you optimize your algorithm to use only O(k) extra space?
vector<int> getRow(int rowIndex) {
    vector<int> res;
    if (rowIndex < 0) return res;
    res.push_back(1);
    if (rowIndex == 0) return res;
    res.push_back(1);
    if (rowIndex == 1) return res;
    for (int i = 2; i <= rowIndex; i++) {
        vector<int> tmp(1, 1);
        for (int j = 0; j < res.size() - 1; j++)
            tmp.push_back(res[j] + res[j + 1]);
        tmp.push_back(1);
        res = tmp;
    }
    return res;
}