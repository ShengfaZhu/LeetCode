// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
// "pwke" is a subsequence and not a substring.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
        return 0;
    int pre = 0, last = 1, max_len = 1;
    while (last < s.size()) { 
        string sub = s.substr(pre, last - pre); 
        size_t index = sub.find(s.at(last)) + pre;
        if (index != string::npos){//found repeated  
            pre = index + 1;
        }
        max_len = max(max_len, last - pre + 1);
        last++; 
    }
    return max_len;
}

int main() {
    string s = "au";
    cout << lengthOfLongestSubstring(s) << endl;
    system("pause");
    return 0;
}
