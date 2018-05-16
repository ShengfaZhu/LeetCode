// The set [1,2,3,...,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, 
// we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

int factorial(int k) {
    int ans = 1;
    for (int i = 2; i <= k; i++)
        ans = ans * i;
    return ans;
}

string getPermutation(int n, int k) {
    string res;
    string map = "0123456789";
    string str;
    for (int i = 1; i <= n; i++)
        str.push_back(map[i]);
    k--; 
    int i = n;
    while (res.size() < n) {
        int curr = k / factorial(i - 1);
        // cout << "curr : " << curr << endl;
        res.push_back(str[curr]);
        str.erase(curr, 1);
        // cout << "str : " << str << endl;
        k = k - curr * factorial(i - 1);
        i--;
    }
    return res;
}

int main() {
    int n = 4, k = 9;
    cout << getPermutation(n, k) << endl;
    system("pause");
    return 0;
}

