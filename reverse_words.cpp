// Given an input string, reverse the string word by word.
// Example:  
// Input: "the sky is blue",
// Output: "blue is sky the".
// Note:
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. 
// However, your reversed string should not contain leading or trailing spaces.
// You need to reduce multiple spaces between two words to 
// a single space in the reversed string.
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void reverseWords(string &s) {
    // 1. reverse whole string
    reverse(s.begin(), s.end());
    // 2. reverse each word
    int i = 0, word_s = -1, word_e = -1;
    while (i < s.size()) {
        if (s[i] != ' ' && word_s == -1)
            word_s = i;
        if (s[i] == ' ' && word_s != -1 && word_e == -1)
            word_e = i;
        if (word_s != -1 && word_e != -1) {
            reverse(s.begin() + word_s, s.begin() + word_e);
            word_s = -1;
            word_e = -1;
        }
        if (word_s != -1 && i == s.size() - 1)
            reverse(s.begin() + word_s, s.end());
        i++;
    }
    // 3. clean extra space
    int j = 0;
    int last_char = s.size() - 1;
    while(s[last_char] == ' ') last_char--;
    while(s[j] == ' ') j++;
    int k = 0;
    for (; k < s.size(); k++) {
        if (j > last_char)
            break;
        while (j < s.size() - 1 && s[j] == ' ' &&  s[j + 1] == ' '){
            j++;
        }
        s[k] = s[j];
        j++;   
    }
    s.resize(k);
}


int main() {
    string s = "   a   b ";
    reverseWords(s);
    cout << s << endl;
    system("pause");
    return 0;
}