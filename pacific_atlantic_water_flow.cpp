#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

void set(pair<int, int> curr, vector<vector<int>>& matrix, 
    queue<pair<int, int>>& q, vector<vector<int>>& status) {
    int num_row = matrix.size(), num_col = matrix[0].size();
    vector<vector<int>> coord = {{curr.first - 1, curr.second}, 
        {curr.first + 1, curr.second}, {curr.first, curr.second - 1}, {curr.first, curr.second + 1}};
    for (int i = 0; i < coord.size(); i++) {
        if (coord[i][0] >= 0 && coord[i][0] < num_row && coord[i][1] >= 0 && 
            coord[i][1] < num_col && status[coord[i][0]][coord[i][1]] != 1) {
            if (matrix[coord[i][0]][coord[i][1]] >= matrix[curr.first][curr.second]) {
                status[coord[i][0]][coord[i][1]] = 1;
                q.push(make_pair(coord[i][0], coord[i][1]));
            }
            else status[coord[i][0]][coord[i][1]] = 2;
        }
    }
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> ans;
    if (matrix.empty()) return ans;
    int num_row = matrix.size(), num_col = matrix[0].size();
    // BFS
    // 0 - undiscovered, 1 - accessible, 2- unaccessible
    vector<vector<int>> status_pac(num_row, vector<int>(num_col, 0)), status_atl(num_row, vector<int>(num_col, 0));
    queue<pair<int, int>> q_pac, q_atl;
    for (int i = 0; i < num_col; i++) {
        status_pac[0][i] = 1;
        status_atl[num_row - 1][i] = 1;
        q_pac.push(make_pair(0, i));
        q_atl.push(make_pair(num_row - 1, i));
    }
    for (int i = 0; i < num_row; i++) {
        status_pac[i][0] = 1;
        status_atl[i][num_col-1] = 1;
        q_pac.push(make_pair(i, 0));
        q_atl.push(make_pair(i, num_col-1));
    }
    while (!q_pac.empty()) {
        int sz = q_pac.size();
        while (sz--) {
            pair<int, int> curr = q_pac.front();
            q_pac.pop();
            set(curr, matrix, q_pac, status_pac);
        }
    }
    while (!q_atl.empty()) {
        int sz = q_atl.size();
        while (sz--) {
            pair<int, int> curr = q_atl.front();
            q_atl.pop();
            set(curr, matrix, q_atl, status_atl);
        }
    }
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            if (status_pac[i][j] == 1 && status_atl[i][j] == 1) {
                ans.push_back(make_pair(i, j));
            }
        }
    }
    return ans;
}

int main () {
    vector<vector<int>> matrix = {{1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4}, 
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}};
    vector<pair<int, int>> ans = pacificAtlantic(matrix);
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << "(" << it->first << ", " << it->second << ")\t";
    system("pause");
    return 0;
}
