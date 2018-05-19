// A message containing letters from A-Z is being 
// encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, 
// determine the total number of ways to decode it.
// Example 1:
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).

#include <iostream>
#include <string>
using namespace std;

int string2num(string s) {
    if (s[0] == '0' && s.size() > 1)
        return 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

// backtrack, but surpass time limit
// int backtrack(string& s, int k, int num) {
//     if (num > 26 || num < 1) 
//         return 0;
//     if (k + 2 < s.size()) {
//         return backtrack(s, k + 1, string2num(s.substr(k + 1, 1))) +
//             backtrack(s, k + 2, string2num(s.substr(k + 1, 2)));
//     }
//     else if(k + 1 < s.size()) {
//         return backtrack(s, k + 1, string2num(s.substr(k + 1, 1)));
//     }
//     else
//         return 1;
// }


int numDecodings(string s) {
    if (s.empty()) return 0;
    if (s.size() == 1)
        if (s[0] - '0' > 0)
            return 1;
        else 
            return 0;
    int mid = s.size() / 2;
    int no_cross = numDecodings(s.substr(0, mid))* numDecodings(s.substr(mid, s.size() - mid));
    int cross = 0;
    int num_cross = string2num(s.substr(mid - 1, 2));
    if (num_cross >= 1 && num_cross <= 26) {
        if (mid - 1 == 0 && s.size() - mid - 1 == 0)
            cross = 1;
        else if (mid - 1 == 0)
            cross = numDecodings(s.substr(mid + 1, s.size() - mid - 1));
        else if (s.size() - mid == 0)
            cross = numDecodings(s.substr(0, mid - 1));
        else
            cross = numDecodings(s.substr(0, mid - 1))* numDecodings(s.substr(mid + 1, s.size() - mid - 1));
    }
    return no_cross + cross;
}

int main() {
    string s = "100";
    cout << numDecodings(s) << endl;
    system("pause");
    return 0;
}