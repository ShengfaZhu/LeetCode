// 200. Number of Islands
void visit(vector<vector<char>>& grid, int row, int col) {
    int num_row = grid.size(), num_col = grid[0].size();
    if (row < 0 || row >= num_row || col < 0 || col >= num_col || grid[row][col] == '0') 
        return;
    grid[row][col] = '0';
    visit(grid, row - 1, col);
    visit(grid, row + 1, col);
    visit(grid, row, col - 1);
    visit(grid, row, col + 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int num_row = grid.size(), num_col = grid[0].size(), count = 0;
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            if (grid[i][j] == '0') continue;
            visit(grid, i, j);
            count++;
        }
    }
    return count;
}