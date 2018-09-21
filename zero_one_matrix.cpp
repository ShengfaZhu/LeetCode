// LeetCode 542.
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <climits>
#include <queue>
using namespace std;

// int bfs(const vector<vector<int>>& matrix, pair<int, int> pos) {
//     int n_row = matrix.size(), n_col = matrix[0].size();
//     queue<pair<int, int> > q;
//     q.push(pos);
//     set<pair<int, int>> visited;
//     visited.emplace(pos);
//     int dist = 0;
//     while (!q.empty()) {
//         int sz = q.size();
//         while(sz--) {
//             pair<int, int> curr = q.front();
//             if (matrix[curr.first][curr.second] == 0) {
//                 return dist;
//             }
//             q.pop();
//             vector<vector<int> > next = {{curr.first - 1, curr.first + 1},
//                                         {curr.second - 1, curr.second + 1}};
//             for (int i = 0; i < 2; ++i) {
//                 pair<int, int> next_pos = {next[0][i],curr.second};
//                 if (next_pos.first >= 0 && next_pos.first < n_row && 
//                     visited.find(next_pos) == visited.end()) {
//                     q.push(next_pos);
//                     visited.emplace(next_pos);
//                 }
//             }
//             for (int i = 0; i < 2; ++i) {
//                 pair<int, int> next_pos = {curr.first, next[1][i]};
//                 if (next_pos.second >= 0 && next_pos.second < n_col && 
//                     visited.find(next_pos) == visited.end()) {
//                     q.push(next_pos);
//                     visited.emplace(next_pos);
//                 }
//             } 
//         }
//         dist++;
//     }
//     return -1;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//     if (matrix.empty()) return matrix;
//     int n_row = matrix.size(), n_col = matrix[0].size();
//     vector<vector<int> > new_matrix(n_row, vector<int>(n_col, 0));
//     for (int i = 0; i < n_row; ++i) {
//         for (int j = 0; j < n_col; ++j) {
//             if (matrix[i][j] == 1) {
//                 pair<int, int> pos = {i, j};
//                 new_matrix[i][j] = bfs(matrix, pos);
//             }
//         }
//     }
//     return new_matrix;
// }

// dynamic solution
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
    if (matrix.empty()) return matrix;
    int n_row = matrix.size(), n_col = matrix[0].size();   
    vector<vector<int>> dist(n_row, vector<int>(n_col, INT_MAX - 1000000));
    for (int i = 0; i < n_row; ++i) {
        for (int j = 0; j < n_col; ++j) {
            if (matrix[i][j] == 0) dist[i][j] = 0;
        }
    }
    // from left and top
    for (int i = 0; i < n_row; ++i) {
        for (int j = 0; j < n_col; ++j) {
            if (i > 0) 
                dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
            if (j > 0)
                dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
        }
    }
    // from bottom and right
    for (int i = n_row - 1; i >= 0; --i) {
        for (int j = n_col - 1; j >= 0; --j) {
            if (i < n_row - 1) 
                dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
            if (j < n_col - 1)
                dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
        }
    }
    return dist;
}
 
int main() {
    vector<vector<int> > matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> new_matrix = updateMatrix(matrix);
    for (int i = 0; i < new_matrix.size(); ++i) {
        for (int j = 0; j < new_matrix[i].size(); ++j) {
            cout << new_matrix[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}