// Given two words (beginWord and endWord), and a dictionary's word list, 
// find the length of shortest transformation sequence from beginWord to 
// endWord, such that:
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord 
// is not a transformed word.
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: As one shortest transformation is 
// "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

bool is_transform(string word1, string word2) {
    int num = 0;
    for (int i = 0; i < word1.size(); i++) {
        if (word1[i] != word2[i]) num++;
    }
    return num == 1;
}

int min_length(const vector<vector<int>>& matrix, int beg, int stop) {
    vector<bool> is_visit(matrix.size(), false);
    vector<int> dist(matrix.size(), INT_MAX);
    queue<int> q;
    is_visit[beg] = true;
    dist[beg] = 1;
    q.push(beg);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int j : matrix[curr]) {
            if (is_visit[j] == false) {
                if (j == stop) return dist[curr] + 1;
                is_visit[j] = true;
                q.push(j);
                dist[j] = dist[curr] + 1;
            }
        }
    }
    return INT_MAX;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // build graph based on adjacent list
    wordList.push_back(beginWord);
    vector<vector<int>> matrix(wordList.size());
    int end = -1;
    for (int i = 0; i < wordList.size(); i++) {
        if (end == -1 && wordList[i] == endWord) end = i;
        for (int j = i + 1; j < wordList.size(); j++) {
            if (is_transform(wordList[i], wordList[j])) {
                matrix[i].push_back(j);
                matrix[j].push_back(i);
            }
        }
    }
    if (end == -1) return 0;//endWord not exist in word list
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    int dist = min_length(matrix, matrix.size()-1, end);
    if (dist < INT_MAX) return dist;
    else return 0;
}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";
    cout << "ladder length " << ladderLength(beginWord, endWord, wordList) << endl;
    system("pause");
    return true;
}