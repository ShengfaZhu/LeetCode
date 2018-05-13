// Determine if a 9x9 Sudoku board is valid. Only the filled cells 
// need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the 
// digits 1-9 without repetition.
#include <iostream>
#include <vector>
using namespace std;

bool is_repeat(vector<vector<char>>& board, int i1, 
    int i2, int j1, int j2) {
    vector<bool> flag(9, false);
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            if (board[i][j] == '.')
                continue;
            else {
                int id = board[i][j] - '0' - 1;
                if (flag[id] == true)
                    return true;
                else 
                    flag[id] = true;
            }
        }
    }
    return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    // check rule 1 & 2
    for (int i = 0; i < 9; i++) {
        if (is_repeat(board, i, i, 0, 8) || (is_repeat(board, 0, 8, i, i)))
            return false;
    } 
    // check rule 3
    for (int i = 0; i < 9; i = i + 3) {
        for (int j = 0; j < 9; j = j + 3) {
            if (is_repeat(board, i, i + 2, j, j + 2))
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    // for (int i = 0; i < board.size(); i++) {
    //     for (int j = 0; j < board[i].size(); j++) {
    //         cout << board[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    cout << isValidSudoku(board) << endl;
    system("pause");
    return 0;
}