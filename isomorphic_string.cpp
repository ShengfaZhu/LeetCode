// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be 
// replaced to get t.

// All occurrences of a character must be replaced with another 
// character while preserving the order of characters. No two 
// characters may map to the same character but a character may map to itself.
#include <string>
#include <assert.h>// header file for assert
#include <vector>
#include <iostream>
using namespace std;

bool isIsomorphic(string s, string t) {
    assert(s.size() == t.size());
    int m[256] = {0}, n[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] != n[t[i]]) return false;
        m[s[i]] = i + 1;
        n[t[i]] = i + 1;
    }
    return true;
}

int main() {
    string s = "ab", t = "aa";
    cout << isIsomorphic(s, t) << endl;
    system("pause");
    return 0;
}