#include <iostream>
#include <bitset>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
private:
    struct cell {
        int value;// cell value 1~9, 0 if uset
        int num_possiblities;// number of possibilities
        // if bitset[v] is 1 then value can't be v
		bitset<10> constraints;
        cell() : value(0), num_possiblities(9), constraints(){};
    };
    vector<vector<cell> > cells = vector<vector<cell>>(9, vector<cell>(9));
    // backtracking state - list of empty cells
	vector<pair<int, int>> bt;

    // set cell[i][j].value = v, and propagates constraints
    bool set(int i, int j, int v) {
        // set cells[i][j]
        cell& c = cells[i][j];
        if (c.value == v) {
            return true;
        }
        if (c.constraints.test(v) == true) {
            return false;
        }
        c.constraints = bitset<10>("1111111110");
        c.constraints.reset(v);
        c.num_possiblities = 1;
        c.value = v;
        // propagate constraints
        for (int k = 0; k < 9; ++k) {
            // row
            if (j != k && !updateConstraints(i, k, v)) {
                return false;
            }
            // col
            if (i != k && !updateConstraints(k, j, v)) {
                return false;
            }
            // 3 * 3 
            int row = (i / 3) * 3 + k / 3;
            int col = (j / 3) * 3 + k % 3;
            if (row != i && col != j && !updateConstraints(row, col, v)) {
                return false;
            }
        }
        return true;
    }

    // update constraints
    bool updateConstraints(int row, int col, int extend_value) {
        cell& c = cells[row][col];
        if (c.constraints[extend_value] == true) {
            return true;
        }
        if (c.value == extend_value) {
            return false;
        }
        c.constraints.set(extend_value, 1);
        if ((--c.num_possiblities) > 1) {
            return true;
        }
        // only one possibilities
        for (int v = 1; v <= 9; ++v) {
            if (c.constraints.test(v) == false) {
                return set(row, col, v);
            }
        }
        assert(false); 
    }

    // find value for empty cell
    bool findValueForEmpty() {
        // collect empty cell
        bt.clear();
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (cells[i][j].value == 0) {
                    bt.push_back(make_pair(i, j));
                }
            }
        }
        // sort to improve backtrack efficience
        sort(bt.begin(), bt.end(), [this](const pair<int, int>& a, const pair<int, int>& b){
            return cells[a.first][a.second].num_possiblities 
            < cells[b.first][b.second].num_possiblities;});
        return backtrack(0);
    }

    // Finds value for all empty cells with index >=k
    bool backtrack(int k) {
        if (k >= bt.size()) {
            return true;
        }
        int i = bt[k].first, j = bt[k].second;
        // only have one possibility
        if (cells[i][j].value != 0) {
            return backtrack(k + 1);
        }
        // more than one possibility
        auto constriants = cells[i][j].constraints;
        // cells will restore from snapshot if not find solution
		// computationally this is cheaper
		// than alternative implementation with undoing the changes
        vector<vector<cell> > snapshot(cells);
        for (int v = 1; v <= 9; ++v) {
            if (constriants.test(v) == false) {
                if (set(i, j, v) == true) {
                    if (backtrack(k + 1)) {
                        return true;
                    }
                }
                cells = snapshot;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !set(i, j, board[i][j] - '0')) {
                    return;
                }
            }
        }
        if (findValueForEmpty() == false) {
            return;//soduku is unsolvable
        }

        // copy solution back to board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (cells[i][j].value) {
                    board[i][j] = cells[i][j].value + '0';
                }
            }
        }
    }
};


int main()
{
    vector<vector<char> > board = 
        {{'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}};
    Solution solu;
    solu.solveSudoku(board);
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board.at(i).size(); ++j) {
            cout << board.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}