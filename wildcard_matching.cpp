#include <iostream>
#include <vector>
#include <string>
using namespace std;

// recursive method
bool isMatchCore(const string& s, const string& p, int i, int j) {
    if (i == s.size() && j == p.size()) {
        return true;
    }
    if (i > s.size() || j >= p.size()) {
        return false;
    }
    if (i < s.size() && s[i] == p[j]) {
        return isMatchCore(s, p, i + 1, j + 1);
    }
    else {
        if (p[j] == '?') {
            return isMatchCore(s, p, i + 1, j + 1);
        }
        else if (p[j] == '*') {
            // more * equal one *
            while (j + 1 < p.size() && p[j + 1] == '*') {
                j++;
            }
            return isMatchCore(s, p, i, j + 1) 
                || isMatchCore(s, p, i + 1, j + 1)
                || isMatchCore(s, p, i + 1, j);
        }
        else return false;
    }
}


// dynamic programming
bool isMatch(string s, string p) {
    if (s.empty() && p.empty()) {
        return true;
    }
    if (p.empty()) {
        return false;
    }
    if (s.empty() && !p.empty()) {
        int i = 0;
        for (; i < p.size(); ++i) {
            if (p[i] != '*') {
                break;
            }
        }
        return i == p.size() ? true : false;
    }
    vector<vector<bool> > dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[s.size()][p.size()] = true;
    // set last row 
    for (int j = p.size() - 1; j >= 0; --j) {
        if (p[j] == '*') {
            dp[s.size()][j] = dp[s.size()][j + 1];
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = p.size() - 1; j >= 0; --j) {
            if (p[j] == '?') {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else if (p[j] == '*') {
                dp[i][j] = dp[i + 1][j] || dp[i + 1][j + 1] || dp[i][j + 1];
            }
            else if (s[i] == p[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}


int main()
{
    string s = "bbaaaabaaaaabbabbabbabbababaabababaabbabaaabbaababababbabaabbabbbbbbaaaaaabaabbbbbabbbbabbabababaaaaa";
    string p = "******aa*bbb*aa*a*bb*ab***bbba*a*babaab*b*aa*a****";
    cout << isMatch(s, p) << endl;
    system("pause");
    return 0;
}