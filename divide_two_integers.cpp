// Given two integers dividend and divisor, 
// divide two integers without using multiplication, 
// division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.
// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2

#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int divide(int dividend, int divisor) {
   if (!divisor || (dividend == INT_MIN && divisor == -1)) {
       return INT_MAX;
   } 
   int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
   long long dvd = labs(dividend);
   long long dvs = labs(divisor);
   int res = 0;
   while (dvd >= dvs) {
       long long tmp = dvs, multiple = 1;
       while (dvd >= (tmp << 1)) {
           tmp = tmp << 1;
           multiple = multiple << 1;
       }
       dvd = dvd - tmp;
       res = res + multiple;
   }
   return sign > 0 ? res : -1 * res;
}

int main() {
    int dividend = -7, divisor = 3;
    cout << divide(dividend, divisor) << endl;
    system("pause");
    return 0;
}