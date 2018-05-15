// Given a positive integer n, generate a square matrix 
// filled with elements from 1 to n2 in spiral order.
// Example:
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> array;
    for (int p = 1; p <= n * n; p++) {
        array.push_back(p);
    }
    int i = 0, p = 0;
    for (; i < n / 2; i++) {
        int j = i, k = i;
        while(k < n - i - 1) {
            matrix[j][k] = array[p];
            p++;
            k++;
        }
        while(j < n - i - 1) {
            matrix[j][k] = array[p];
            p++;
            j++;
        }
        while(k > i) {
            matrix[j][k] = array[p];
            p++;
            k--;
        }
        while(j > i) {
            matrix[j][k] = array[p];
            p++;
            j--;           
        }
    }
    if (i == (n - 1) / 2) {
        matrix[i][i] = array[p];
    }
    return matrix;
}

int main() {
    int n = 1;
    vector<vector<int>> matrix = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}