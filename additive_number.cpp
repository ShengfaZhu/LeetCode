// 306. Additive Number
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

string string_plus(string str1, string str2) {
    if (str1.empty()) return str2;
    if (str2.empty()) return str1;
    string sum;
    int i = str1.size() - 1, j = str2.size() - 1;
    int step = 0;// step for next digit
    while (i >= 0 || j >= 0) {
        int num1 = i >= 0 ? (str1[i] - '0') : 0;
        int num2 = j >= 0 ? (str2[j] - '0') : 0;
        int tmp_sum = num1 + num2 + step;
        if (tmp_sum >= 10) {
            step = 1;
            tmp_sum -= 10;
        }
        else step = 0;
        sum.push_back('0' + tmp_sum);
        i--;
        j--;
    }
    if (step) sum.push_back(step + '0');
    reverse(sum.begin(), sum.end());
    return sum;
}

bool isAdditiveNumber(string num, int start, int len1, int len2) {
    if (num.size() == start + len1 + len2) return true;
    if (num.size() - start - len1 - len2 < max(len1, len2)) return false;
    if (num[start + len1] == '0' && len2 > 1) return false;
    string tmp_sum = string_plus(num.substr(start, len1), num.substr(start+len1, len2));
    if (tmp_sum == num.substr(start+len1+len2, tmp_sum.size()))
        return isAdditiveNumber(num, start + len1, len2, tmp_sum.size());
    else return false;
}

bool isAdditiveNumber(string num) {
    assert(!num.empty());
    for (int len1 = 1; len1 <= num.size() / 2; len1++) {
        if (num[0] == '0' && len1 > 1) return false;
        for (int len2 = 1; len2 + len1 < num.size(); len2++) {
            if (num.size() - len1 - len2 < max(len1, len2)) break;
            if (isAdditiveNumber(num, 0, len1, len2)) return true;
        }
    }
    return false;
}

int main() {
    string num = "198019823962";
    cout << isAdditiveNumber(num) << endl;
    system("pause");
    return 0;
}