// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
    string res;
    string map = "012";
    int i = a.size() - 1, j = b.size() - 1, step = 0;
    while(i >= 0 || j >= 0) {
        int tmp = (i >= 0 ? a[i] - '0' : 0) + ( j >= 0 ? b[j] - '0' : 0) + step;
        if (tmp >= 2) {
            tmp = tmp - 2;
            step = 1;
        }
        else {
            step = 0;
        }
        res.push_back(map[tmp]);
        i--, j--;
    }
    if (step == 1)
        res.push_back('1');
    string res_r;
    for(int k = res.size() - 1; k >= 0; k--)
        res_r.push_back(res[k]);
    return res_r;
}

int main() {
    string a = "1010", b = "1011";
    cout << addBinary(a, b) << endl;
    system("pause");
    return 0;
}