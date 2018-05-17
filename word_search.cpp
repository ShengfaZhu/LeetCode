// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent 
// cell, where "adjacent" cells are those horizontally or vertically 
// neighboring. The same letter cell may not be used more than once.
// Example:
// board =
// {
//   {'A','B','C','E'},
//   {'S','F','C','S'},
//   {'A','D','E','E'}
// }
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool backtrack(vector<vector<char>>& board, string& word, vector<vector<bool>> is_used, int row, int col, int k) {
    if (k >= word.size())
        return true;
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()
        || is_used[row][col] == true || board[row][col] != word[k]) {
        return false;
    }
    is_used[row][col] = true;
    return backtrack(board, word, is_used, row - 1, col, k + 1) || 
        backtrack(board, word, is_used, row, col - 1, k + 1) ||
        backtrack(board, word, is_used, row + 1, col, k + 1) ||
        backtrack(board, word, is_used, row, col + 1, k + 1);
}

bool exist(vector<vector<char>>& board, string word) { 
    if (board.empty())
        return false;
    int n_row = board.size(), n_col = board[0].size();
    vector<vector<bool>> is_used(n_row, vector<bool>(n_col, false));
    for (int i = 0; i < n_row; i++) {
        for (int j = 0; j < n_col; j++) {
            if (backtrack(board, word, is_used, i, j, 0))
                return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
    };
    string word = "";
    cout << exist(board, word) << endl;
    system("pause");
    return 0;
}