// Given a string containing only digits, restore it 
// by returning all possible valid IP address combinations.
// ip地址分为4部分，每部分数值为0-255,且由0开头，只能为0， 01,001为非法
// Example:
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int string2int(string s) {
    if (s.size() > 1 && s[0] == '0')
        return 256;
    int ans = 0;
    int i = 0;
    while(i < s.size()) {
        ans = ans * 10 + s[i] - '0';
        i++;
    }
    return ans;
}

void backtrack(vector<string>& res, string& s, string local, int len, int k) {
    if (local.size() - k + 1 + len > s.size()) return;
    if (k > 0) {
        string segment = s.substr(local.size() - k + 1, len);
        int num = string2int(segment);
        if (num > 255) return;
        local = local + segment;
        local.push_back('.');
    }
    if (k == 4){
        if (local.size() == s.size() + 4) {//取完 
            local.pop_back();
            res.push_back(local);
        }
        return;
    }
    backtrack(res, s, local, 1, k + 1);
    backtrack(res, s, local, 2, k + 1);
    backtrack(res, s, local, 3, k + 1);
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string local = "";
    backtrack(res, s, local, 0, 0);
    return res;
}

int main() {
    string s = "010010";
    vector<string> res = restoreIpAddresses(s);
    for(string& str : res)
        cout << str << endl;
    system("pause");
    return 0;
}
