#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

string num2string (long long num) {
    if (num == 0) return "0";
    string map = "0123456789", ans;
    while (num) {
        ans.push_back(map[num - (num / 10) * 10]);
        num = num / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string fractionToDecimal(int numerator, int denominator) {
    string res;
    long long nume = numerator, deno = denominator;
    if (nume < 0 && deno > 0) { 
        nume = -1 * nume;
        res.push_back('-');
    }
    if (nume > 0 && deno < 0) {
        deno = -1 * deno;
        res.push_back('-');
    }
    res = res + num2string(nume / deno);
    long long residual = nume - (nume / deno) * deno;
    if (residual == 0) return res;
    res.push_back('.');
    vector<int> record, loca;
    int repeat = -1;
    while (residual) {
        residual = residual * 10;
        for (int i = 0; i < record.size(); i++){
            if (record[i] == residual){
                repeat = loca[i];
                break;
            }
        }
        if (repeat != -1) break;
        record.push_back(residual);
        loca.push_back(res.size());
        res = res + num2string(residual / deno);
        residual = residual - (residual / deno) * deno;
    }
    if (repeat != -1) {
        res.insert(repeat, "(");
        res.push_back(')');
    }
    return res;
}

int main() {
    int numerator = -50, denominator = 8;
    cout << fractionToDecimal(numerator, denominator) << endl;;
    system("pause");
    return 0;
}