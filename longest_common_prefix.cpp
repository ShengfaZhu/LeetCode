// Write a function to find the longest common prefix 
// string amongst an array of strings.
// If there is no common prefix, return an empty string "".

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string prefix;
    int i = 0, j = 0;
    char ch = ' ';
    bool is_terminate = false;
    while(true) {
        j = 0;
        if (j < strs.size() && i < strs[j].size())
            ch = strs[j][i];
        else
            return prefix;
        for (; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != ch){
                is_terminate = true;
                break;
            }      
        }
        if (is_terminate) {
            return prefix;
        }
        else {
            prefix.push_back(ch);
            i++;
        }
    }
}

int main() {
    vector<string> words = {"dog","racecar","car"};
    cout << longestCommonPrefix(words) << endl;
    system("pause");
    return 0;
}