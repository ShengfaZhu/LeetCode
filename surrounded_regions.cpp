// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// Example:
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:
// Surrounded regions shouldn’t be on the border, which means that any 'O' 
// on the border of the board are not flipped to 'X'. Any 'O' that is not 
// on the border and it is not connected to an 'O' on the border will be 
// flipped to 'X'. Two cells are connected if they are adjacent cells 
// connected horizontally or vertically.
#include <iostream>
#include <vector>
using namespace std;


void detect(vector<vector<char>>& board, int row, int col) {
    int num_row = board.size(), num_col = board[0].size();
    if (row < 0 || row >= num_row || col < 0 || col >= num_col) return;
    if (board[row][col] == 'O'){
        board[row][col] = '1';
        detect(board, row, col - 1);
        detect(board, row - 1, col);
        detect(board, row, col + 1);
        detect(board, row + 1, col);
    }
}

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int num_row = board.size(), num_col = board[0].size();
    for (int i = 0; i < num_row; i++) {
        if (board[i][0] == 'O') detect(board, i, 0);// 第一列
        if (board[i][num_col-1] == 'O') detect(board, i, num_col-1);//最后一列
    }
    for (int i = 0; i < num_col; i++) {
        if (board[0][i] == 'O') detect(board, 0, i);//第一行
        if (board[num_row - 1][i] == 'O') detect(board, num_row - 1, i);//最后一行
    }
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '1') board[i][j] = 'O';
    }
    
}

int main() {
    vector<vector<char>> board = {{'O', 'O'}, {'O','O'}};
    solve(board);
    int num_row = board.size(), num_col = board[0].size();
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++) {
            cout << board[i][j] << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}