// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// Note:
// You have to rotate the image in-place, which means you 
// have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.
// Example 1:
// Given input matrix = 
// {
//   {1,2,3},
//   {4,5,6},
//   {7,8,9}
// },
// rotate the input matrix in-place such that it becomes:
// {
//   {7,4,1},
//   {8,5,2},
//   {9,6,3}
// }

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int sz = matrix.size();
    if (sz == 0)
        return;
    for (int i = 0; i < sz / 2; i++) {
        for (int j = i; j < sz - i - 1; j++) {
            int z = matrix[i][j];
            matrix[i][j] = matrix[sz - j - 1][i];
            matrix[sz - j - 1][i] = matrix[sz - i - 1][sz - j - 1];
            matrix[sz - i - 1][sz - j - 1] = matrix[j][sz - i - 1];
            matrix[j][sz - i - 1] = z;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        };
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}