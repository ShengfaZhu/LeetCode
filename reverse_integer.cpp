// Given a 32-bit signed integer, reverse digits of an integer.
// Example 1:
// Input: 123
// Output: 321

// Example 2:
// Input: -123
// Output: -321

// Example 3:
// Input: 120
// Output: 21

#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x) {
    long long y = 0;
    while(x != 0) {       
        y = y * 10 + (x % 10);
        x = x / 10;
    }
     if (y < pow(-2, 31) || y > (pow(2, 31) - 1))
        return 0;
    return y;
}

int main() {
    int x = 1534236469;
    cout << reverse(x) << endl;
    system("pause");
    return 0;
}