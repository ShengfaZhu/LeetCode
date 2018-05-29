#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string>& wordSet) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]){
                if (wordSet.find(s.substr(j, i-j)) != wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}

bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty()) return true;
    unordered_set<string> wordSet;
    for (auto str : wordDict) wordSet.emplace(str);
    return wordBreak(s, wordSet);
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    system("pause");
    return 0;
}