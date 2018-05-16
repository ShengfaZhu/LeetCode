// mplement int sqrt(int x).
// Compute and return the square root of x, where x is 
// guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits 
// are truncated and only the integer part of the result is returned.

#include <iostream>
#include <limits.h>
using namespace std;

// binary search
int mySqrt(int x) {
    if (x == 0)
        return 0;
    int low = 1, high = x;
    while(low < high) {
        int mid = low + (high - low) /2;
        if (mid > x / mid) {
            high = mid - 1;
        } 
        else {
            if ((mid + 1) > x /(mid + 1))
                return mid;
            else {
                low = mid + 1;
            }
        }
    }
}

int main() {
    int num = 5;
    cout <<"Sqrt : " << mySqrt(num) << endl;
    system("pause");
    return 0;
}