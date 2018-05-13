// Given two non-negative integers num1 and num2 represented 
// as strings, return the product of num1 and num2, 
// also represented as a string.
// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, 
// except the number 0 itself.
// // You must not use any built-in BigInteger library 
// or convert the inputs to integer directly.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int string2int(string num) {
    int i = 0;
    for(char& c : num) {
        i = i * 10 + (c - '0');
    }
    return i;
}

string int2string(int num) {
    string map = "0123456789", ans = "";
    if (num == 0)
        return "0";
    while(num) {
        ans = map[num % 10] + ans;
        num = num / 10;
    }
    return ans;
}

string string_plus(string num1, string num2) {
    if (num1.empty() && num2.empty())
        return "0";
    string map = "0123456789";
    string sum = "";
    int i1 = num1.size() - 1, i2 = num2.size() - 1, step = 0;
    while (i1 >= 0 || i2 >= 0) {
        int tmp1 = 0, tmp2 = 0;
        if (i1 >= 0) {
            tmp1 = num1[i1] - '0';
        }   
        if (i2 >= 0) {
            tmp2 = num2[i2] - '0';
        }
        int tmp_sum = tmp1 + tmp2 + step;
        if (tmp_sum >= 10) {
            sum = map[tmp_sum - 10] + sum;
            step = 1;
        }
        else {
            sum = map[tmp_sum] + sum;
            step = 0;
        }
        i1--;
        i2--;
    }
    if (step == 1) {
        sum = '1' + sum;
    }
    return sum;
}

string multiply(string num1, string num2) {
    string res = "";
    // 分解
    vector<int> n1, n2;
    vector<int> order1, order2;
    int count = 0;
    for (int i = num1.size() - 1; i >= 0; i = i - 4) {
        int ind = i - 3 >= 0 ? i - 3 : 0;
        n1.push_back(string2int(num1.substr(ind, i - ind + 1)));
        order1.push_back(count);
        count = count +4;
    }
    // for (int& i : n1) {
    //     cout << i << "\t";
    // }
    // cout << endl;
    // for (int& i : order1) {
    //     cout << i << "\t";
    // }
    // cout << endl;
    count = 0;
    for (int i = num2.size() - 1; i >= 0; i = i - 4) {
        int ind = i - 3 >= 0 ? i - 3 : 0;
        n2.push_back(string2int(num2.substr(ind, i - ind + 1)));
        order2.push_back(count);
        count = count + 4;
    }
    // 乘法分配率相乘
    for (int i = 0; i < n1.size(); i++) {
        for (int j = 0; j < n2.size(); j++){
            string tmp = int2string(n1[i] * n2[j]);
            int num_zeros = order1[i] + order2[j];
            while (tmp != "0" && num_zeros) {
                tmp.push_back('0');
                num_zeros--;
            }
            res = string_plus(res, tmp);
        }
    }
    return res;
}

int main() {
    string num1 = "0", num2 = "4561443542";
    cout << multiply(num1, num2) << endl;
    system("pause");
    return 0;
}