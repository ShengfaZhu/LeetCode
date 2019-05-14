#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// using bfs to compute distance between begin and each node
void bfs(const vector<vector<size_t> >& matrix, size_t index_begin, vector<int>* dist) {
    vector<bool> is_visited(matrix.size(), false);
    is_visited[index_begin] = true;
    dist->at(index_begin) = 1;
    queue<int> q;
    q.push(index_begin);
    while (!q.empty())
    {
        size_t curr = q.front();
        q.pop();
        for (auto neib : matrix[curr]) {
            if (is_visited[neib] == false) {
                is_visited[neib] = true;
                dist->at(neib) = dist->at(curr) + 1;
                q.push(neib);
            }
        }
    }
}

bool isTransform(const string& str1, const string& str2) {
    int count = 0;
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            count++;
        }
    }
    return count == 1;
}

// using dfs to output all shortest path form beginWord to endWord
void dfs(const vector<vector<size_t> >& matrix, const vector<string>& wordList, size_t end_index, 
    const vector<int>& dist, vector<vector<string> >* res, vector<size_t>* path) {
    if (path->back() == end_index && path->size() == dist[end_index]) {
        vector<string> curr_path;
        for (size_t index : *path) {
            curr_path.push_back(wordList[index]);
        }
        res->push_back(curr_path);
        return;
    }
    if (path->size() > dist[end_index]) {
        return;
    }
    size_t curr_index = path->back();
    for (size_t index : matrix[curr_index]) {
        if (dist[index] == dist[curr_index] + 1) {
            path->push_back(index);
            dfs(matrix, wordList, end_index, dist, res, path);
            path->pop_back();
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // build graph by adjacent matrix
    wordList.push_back(beginWord);
    vector<vector<size_t>> matrix(wordList.size());
    size_t index_end = -1;
    for (size_t i = 0; i < wordList.size(); ++i) {
        for (size_t j = i + 1; j < wordList.size(); ++j) {
            if (index_end == -1 && wordList[i] == endWord) {
                index_end = i;
            }
            if (isTransform(wordList[i], wordList[j]) == true) {
                matrix[i].push_back(j);
                matrix[j].push_back(i);
            }
        }
    }
    vector<vector<string>> res;
    if (index_end == -1) {
        return res;
    }
    vector<int> dist(matrix.size(), INT_MAX);
    // find distance from begin to each node
    bfs(matrix, matrix.size() - 1, &dist);
    for (int& d : dist) {
        cout << d << "\t";
    }
    if (dist[index_end] < INT_MAX) {
        // output all shortest path
        vector<size_t> path;
        path.push_back(wordList.size() - 1);
        dfs(matrix, wordList, index_end, dist, &res, &path);
    }
    return res;

}

int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";
    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);
    for (size_t i = 0; i < res.size(); ++i) {
        for (string& str : res[i]) {
            cout << str << "->";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}