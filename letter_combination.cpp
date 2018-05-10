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
#include <queue>
#include <unordered_map>
using namespace std;

// recursive version
// vector<string> helper(string digits, vector<string> res, int k) {
//     if (k == digits.size()) 
//         return res;
//     vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
//         "tuv", "wxyz"};
//     unordered_map<char, int> char2int = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
//         {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
//     vector<string> temp;
//     string curr = map[char2int[digits[k]] - 2];
//     if (res.empty()) {
//         for (int j = 0; j < curr.size(); j++) {
//             string ch = "0";
//             ch[0] = curr[j];
//             temp.push_back(ch);
//         }       
//     }
//     else {
//         for (int i = 0; i < res.size(); i++) {            
//             for (int j = 0; j < curr.size(); j++) {
//                 temp.push_back(res[i] + curr[j]);
//             }
//         }
//     }
//     return helper(digits, temp, k + 1);
// }

// vector<string> letterCombinations(string digits) {
//     vector<string> res;
//     return helper(digits, res, 0);
// }

//BFS, iterative version
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty())
        return ans;
    queue<string> res;
    res.push("");//seed for initialization
    vector<string> map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"};
    for (int i = 0, len = 0; i < digits.size(); i++, len++) {
        int num = digits.at(i) - '0';
        if (num < 2 || num > 9) {
            len--;
            continue;
        }           
        string tmp = map.at(num);
        while(res.front().size() == len) {
            string curr = res.front();
            res.pop();
            for (int j = 0; j < tmp.size(); j++) {
                res.push(curr + tmp.substr(j, 1));
            }
        }
    }
    //convert result in queue to answer in vector
    while(!res.empty()) {
        ans.push_back(res.front());
        res.pop();
    }
    return ans;
}

int main() {
    string s = "1203";
    vector<string> letter = letterCombinations(s);
    for (int i = 0; i < letter.size(); i++) {
        cout << letter[i] << endl;
    }
    system("pause");
    return 0;
}