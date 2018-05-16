// You are climbing a stair case. It takes n steps 
// to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many 
// distinct ways can you climb to the top?
// Note: Given n will be a positive integer.

#include <iostream>
using namespace std;

int climbStairs(int n) {
    int pre = 1, ans = 1;
    int i = 2;
    while(i <= n) {
        ans = pre + ans;
        pre = ans - pre;
        i++;
    }
    return ans;
}

int main() {
    int n = 3;
    cout << climbStairs(n) << endl;
    system("pause");
    return 0;
}