// Implement pow(x, n), which calculates x raised to the power n (xn).
// Example 1:
// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]

#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

double help(double x, long long n) {
    if (n == 0)
        return 1.0;
    if (n < 0) {
        n = -n;
        x = 1.0 / x;
    }
    return (n % 2 == 0) ? pow(x, n/2) * pow(x, n/2) : x * pow(x, (n-1)/2) * pow(x, (n-1)/2);
}

double myPow(double x, int n) {
    return help(x, n);
}

int main() {
    double x = 2.0;
    int n = -2;
    cout << myPow(x, n) << endl;
    system("pause");
    return 0;
}