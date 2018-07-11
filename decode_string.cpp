// 394. Decode String
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> nums;
    stack<string> str;
    string res;
    auto is_digit = [](char c) { return c >= '0' && c <= '9';};
    int i = 0;
    while (i < s.size()) {
        if (is_digit(s[i])) {
            int k = 0;
            while (is_digit(s[i])) {
                k = k * 10 + s[i] - '0';
                i++;
            }
            nums.push(k);
        }
        else if (s[i] == '[') {
            str.push(res);
            res = "";
            i++;
        }
        else if (s[i] == ']') {
            string tmp = str.top();
            str.pop();
            int repeat = nums.top();
            nums.pop();
            for (int j = 0; j < repeat; j++) 
                tmp = tmp + res;
            res = tmp;
            i++;
        }
        else {
            res.push_back(s[i]);
            i++;
        }
    }
    return res;
}

int main() {
    string s = "2[abc]3[cd]ef";
    cout << decodeString(s) << endl;
    system("pause");
    return 0;
}