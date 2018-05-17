// Write an efficient algorithm that searches for a 
// value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last 
// integer of the previous row.
// Example 1:
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true

#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
        return false;
    int n_row = matrix.size(), n_col = matrix[0].size();
    int low = 0, high = n_row * n_col - 1;
    while(low <= high) {
        cout << "low : " << low << endl;
        cout << "high : " << high << endl;
        int mid = low + (high - low) / 2;
        int row = mid / n_col;
        int col = mid - (row * n_col);
        if (matrix[row][col] == target) 
            return true;
        else {
            if (matrix[row][col] < target)
                low = mid + 1;
            else {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    system("pause");
    return 0;
}