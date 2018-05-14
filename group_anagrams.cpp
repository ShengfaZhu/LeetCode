// Given an array of strings, group anagrams together.
// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    vector<vector<int>> count;
    for(string& s : strs) {
        vector<int> tmp(26, 0);
        for (char& c : s) {
            tmp[c - 'a']++;
        }
        int i = 0;
        for (; i < count.size(); i++) {
            if (tmp == count[i]) {
                res[i].push_back(s);
                break;
            }
        }
        if (i == count.size()) {
            count.push_back(tmp);
            res.push_back(vector<string>(1, s));
        }
    }
    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (string& s : res[i])
            cout << s << "\t";
        cout << endl;
    }
    system("pause");
    return 0;
}
