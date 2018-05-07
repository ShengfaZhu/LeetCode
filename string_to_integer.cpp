// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters 
// as necessary until the first non-whitespace character is found. 
// Then, starting from this character, takes an optional initial plus 
// or minus sign followed by as many numerical digits as possible, 
// and interprets them as a numerical value.

// The string can contain additional characters after those that form 
// the integral number, which are ignored and have no effect on the 
// behavior of this function.

// If the first sequence of non-whitespace characters in str is not 
// a valid integral number, or if no such sequence exists because 
// either str is empty or it contains only whitespace characters, 
// no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int char2digit(char c) {
    string s = "0123456789";
    int i = 0;
    for (; i <= 9; i++) {
        if (s.at(i) == c) {
            break;
        }
    }
    return i;
}

int myAtoi(string str) {
    if (str.empty()) {
        return 0;
    }
    long long num = 0;
    string s = "0123456789";
    int i = 0;
    //go to the first non-whitespace
    while (i < str.size() && str.at(i) == ' ') {
        i++;
    }
    if (i >= str.size()) return num;
    //first non-whitespace is not +,- or digit
    if (str.at(i) != '+' && str.at(i) != '-' && s.find(str.at(i)) == string::npos)
        return 0;
    //positive or negative of number
    int flag = 1;
    if (str.at(i) == '+') {
        i++;
    }
    else if (str.at(i) == '-') {
        flag = -1;
        i++;
    }
    for (; i < str.size(); i++) {
        if (s.find(str.at(i)) != string::npos) {
            num = num * 10 + char2digit(str.at(i)) * flag;
            if (num < INT_MIN)
                return INT_MIN;
            if (num > INT_MAX)
                return INT_MAX;   
        }
        else
            break;
    }
    return num;
}

int main() {
    string s = "9223372036854775808";
    cout << myAtoi(s) << endl;
    system("pause");
    return 0;
}