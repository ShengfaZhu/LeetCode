// Given a m x n matrix, if an element is 0, set its 
// entire row and column to 0. Do it in-place.
// Example 1:
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

#include <iostream>
#include <vector>
using namespace std;

// O(m + n) space
// void setZeroes(vector<vector<int>>& matrix) {
//     if (matrix.empty()) 
//         return;
//     int row = matrix.size(), col = matrix[0].size();
//     vector<bool> zero_row(row, false), zero_col(col, false);
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if (matrix[i][j] == 0) {
//                 zero_row[i] = true;
//                 zero_col[j] = true;
//             }
//         }
//     }
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if (zero_row[i] == true || zero_col[j] == true)  {
//                 matrix[i][j] = 0;
//             }
//         }
//     }   
// }


// O(1) space
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) 
        return;
    int row = matrix.size(), col = matrix[0].size();
    int row0 = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                if (i == 0) 
                    row0 = 0;
                else 
                    matrix[i][0] = 0;
            }
        }
    }
    // set row except first row
    for (int i = 1; i < row; i++) {
        if (matrix[i][0] != 0)
            continue;
        for (int j = 1; j < col; j++)
                matrix[i][j] = 0;
    }
    // set col
    for (int j = 0; j < col; j++) {
        if (matrix[0][j] != 0)
            continue;
        for (int i = 1; i < row; i++)
            matrix[i][j] = 0;
    }
    // set first row
    if (row0 == 0)
        for (int j = 0; j < col; j++)
            matrix[0][j] = 0;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}