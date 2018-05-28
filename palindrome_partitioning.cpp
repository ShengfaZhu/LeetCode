// Given a string s, partition s such that every substring 
// of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// Example:
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool is_palindrome(string str) {
    if (str.empty()) return true;
    int i = 0, j = str.size() - 1;
    while(i < j) {
        if (str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

void backtrack(string& s, vector<vector<string>>& res, vector<string> local, int curr, int k) {
    if (k >= int(s.size())) return;
    if (curr >= -1) {
        string tmp = s.substr(curr + 1, k - curr);
        if (is_palindrome(tmp) == false) return;
        local.push_back(tmp);
    }
    curr = k;
    if (k == s.size()-1) {
        res.push_back(local);
        return;
    }
    for (int i = curr + 1; i < s.size(); i++)
        backtrack(s, res, local, curr, i);
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> local;
    backtrack(s, res, local, -2, -1);
    return res;
}

int main() {
    string s = "aab";
    vector<vector<string>> res = partition(s);
    cout << "size : " << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j <res[i].size(); j++) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}