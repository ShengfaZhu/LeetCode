// Given a matrix of m x n elements (m rows, n columns), 
// return all elements of the matrix in spiral order.
// Example 1:
// Input:
// {
//  { 1, 2, 3 },
//  { 4, 5, 6 },
//  { 7, 8, 9 }
// }
// Output: {1,2,3,6,9,8,7,4,5}

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty())
        return res;
    int num_row = matrix.size(), num_col = matrix[0].size();
    int i = 0, flag = 0;
    for (; i <= (num_row) / 2; i++) {
        if (num_row - i - 1 < i || num_col - i - 1 < i) {
            break;
        }
        if (num_row - i - 1 == i){//剩一行
            flag = 1;
            break;
        }
        if (num_col - i - 1 == i) {//剩一列
            flag = 2;
            break;
        }
        int j = i, k = i;
        while(k < num_col - i - 1) {
            res.push_back(matrix[j][k]);
            k++;
        }
        while(j < num_row - i - 1) {
            res.push_back(matrix[j][k]);
            j++;
        }
        while(k > i) {
            res.push_back(matrix[j][k]);
            k--;
        }
        while(j > i) {
            res.push_back(matrix[j][k]);
            j--;           
        }
    }
    cout << "flag : " << flag << endl;
    cout << "i : " << i << endl;
    if (flag == 1) {//剩一行
        int j = i;
        while(j < num_col - i) {
            res.push_back(matrix[i][j]);
            j++;
        }
        return res;
    }
    if (flag == 2) {//剩一列
        int j = i;
        while(j < num_row - i) {
            res.push_back(matrix[j][i]);
            j++;
        }
        return res;
    }
    return res;
}

int main() {
    vector<vector<int>> matrix  = {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
    vector<int> res = spiralOrder(matrix);
    for (int& i : res) {
        cout << i << "\t";
    }
    system("pause");
    return 0;
}