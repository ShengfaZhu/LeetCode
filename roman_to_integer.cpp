// Roman numerals are represented by seven different 
// symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// Given a roman numeral, convert it to an integer. 
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> symbols({{'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
    unordered_map<char, int> priority({{'I', 1}, {'V', 2},
        {'X', 3}, {'L', 4}, {'C', 5}, {'D', 6}, {'M', 7}});
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && priority[s[i+1]] > priority[s[i]])
            num -= symbols[s[i]];
        else 
            num += symbols[s[i]];    
    }
    return num;
}

int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    system("pause");
    return 0;
}