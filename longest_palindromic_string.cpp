// Given a string s, find the longest palindromic substring in s. 
// You may assume that the maximum length of s is 1000.
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: "cbbd"
// Output: "bb"

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    string longest_substring;
    int i = 0, left = 0, right = 0;
    while(i < s.size()) {
        left = i - 1;
        while(true)
            if (i + 1 >= s.size() || s.at(i + 1) != s.at(i))
                break;
            else i++;
        right = i + 1;
        while(left >= 0 && right < s.size() && s.at(left) == s.at(right)) {
            left--, right++;
        }
        if (right - left - 1 > longest_substring.size())
            longest_substring = s.substr(left + 1, right - left - 1);
        i++;
    }
    return longest_substring;
}

int main() {
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    system("pause");
    return 0;
}