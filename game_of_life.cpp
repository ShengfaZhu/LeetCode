// 289. Game of Life
int count_live_neigh(vector<vector<int>>& board, int row, int col) {
    int num_row = board.size(), num_col = board[0].size(), num_live_neigh = 0;
    for (int i = max(0, row - 1); i <= min(num_row - 1, row + 1); i++) {
        for (int j = max(0, col - 1); j <= min(num_col - 1, col + 1); j++) {
            if (i == row && j == col) continue;
            if ((board[i][j] & 1) == 1) num_live_neigh++;                
        }
    }
    return num_live_neigh;
}

/* [2nd bit, 1st bit] = [next state, current state]
- 00  dead (next) <- dead (current)
- 01  dead (next) <- live (current)  
- 10  live (next) <- dead (current)  
- 11  live (next) <- live (current)  */
void gameOfLife(vector<vector<int>>& board) {
    if (board.empty()) return;
    int num_row = board.size(), num_col = board[0].size();
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            int num_live_neigh = count_live_neigh(board, i, j);
            if ((board[i][j] & 1) == 1) {
                if (num_live_neigh == 2 || num_live_neigh == 3) board[i][j] = 3;                    
            }
            else {
                if (num_live_neigh == 3) board[i][j] = 2;
            } 
                
        }
    }
    
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            board[i][j] = board[i][j] >> 1;
        }
    }
}