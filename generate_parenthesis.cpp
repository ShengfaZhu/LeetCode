// Given n pairs of parentheses, write a function to 
// generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// backtrack 
void backtrack(vector<string> &ans, string sub, int n, int left, int right) {
    if (right > left || left > n)
        return;
    if (right == n) {
        ans.push_back(sub);
        return;
    }
    backtrack(ans, sub + "(", n, left + 1, right);
    backtrack(ans, sub + ")", n, left, right + 1);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, "", n, 0, 0);
    return ans;
}

int main() {
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (string& s : ans)
        cout << s << endl;
    system("pause");
    return 0;
}