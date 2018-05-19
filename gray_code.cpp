//  The gray code is a binary numeral system where 
//  two successive values differ in only one bit.
// Given a non-negative integer n representing the 
// total number of bits in the code, print the sequence of gray code. 
// A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res(1, 0);
    for (int i = 0; i < n; i++) {
        int sz = res.size();
        for (int j = sz - 1; j >= 0; j--)
            res.push_back(res[j] | 1 << i);
    }
    return res;
}

int main() {
    int n = 2;
    vector<int> nums = grayCode(n);
    for (int& i : nums)
        cout << i << "\t";
    system("pause");
    return 0;
}