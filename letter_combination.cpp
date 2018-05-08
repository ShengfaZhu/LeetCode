// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) 
// is given below. Note that 1 does not map to any letters.

// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> helper(string digits, vector<string> res, int k) {
    if (k == digits.size()) 
        return res;
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"};
    unordered_map<char, int> char2int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
        {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    vector<string> temp;
    string curr = map[char2int[digits[k]] - 2];
    if (res.empty()) {
        for (int j = 0; j < curr.size(); j++) {
            string ch = "0";
            ch[0] = curr[j];
            temp.push_back(ch);
        }       
    }
    else {
        for (int i = 0; i < res.size(); i++) {            
            for (int j = 0; j < curr.size(); j++) {
                temp.push_back(res[i] + curr[j]);
            }
        }
    }
    return helper(digits, temp, k + 1);
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    return helper(digits, res, 0);
}

int main() {
    string s = "23";
    vector<string> letter = letterCombinations(s);
    for (int i = 0; i < letter.size(); i++) {
        cout << letter[i] << endl;
    }
    system("pause");
    return 0;
}