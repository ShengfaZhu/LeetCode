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
// Given an integer, convert it to a roman numeral. 
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <unordered_map>
using namespace std;

string intToRoman(int num) {
    //six specical instances:4, 9, 40, 90, 400, 900
    unordered_map<int, string> sub({{4, "IV"}, {9, "IX"}, 
        {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}});
    unordered_map<int, string> symbols({{1, "I"}, {5, "V"},
        {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}});
    vector<int> digits = {1000, 500, 100, 50, 10, 5, 1};
    vector<int> detect_spe = {INT_MAX, 900, 400, 90, 40, 9, 4};
    int res = num, count = 0, decrease = 0;
    string roman;
    for (int i = 0; i < digits.size(); i++) {
        if (res >= detect_spe[i]) {
            roman += (sub[detect_spe[i]]);
            decrease = detect_spe[i];
        }
        else {
            count = (res / digits[i]);
            for(int j = 0; j < count; j++)
                roman += (symbols[digits[i]]);
            decrease = count * digits[i];
        }
        res = res - decrease;
        if (res <= 0)
            break;
    }
    return roman;
}

int main() {
    int num = 9;
    cout << intToRoman(num) << endl;
    system("pause");
    return 0;
}