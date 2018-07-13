#include <iostream>
#include <cmath>
using namespace std;

int findNthDigit(int n) {
    long long v = n;
    int i = 0;
    while (v >= 0) {
        i++;
        v = v - 9 * pow(10, i-1) * i;
    }
    v = v + 9 * pow(10, i-1) * i;
    int num = v / i + pow(10, i-1);
    int id = v % i;
    if (id == 0) {
        return (num - 1) % 10;
    }
    else {
        int res = 0;
        while (id <= i) {
            res = num % 10;
            num = num / 10;
            i--;
        }
        return res;
    }
}

int main() {
    int n = 1000000000;
    cout << findNthDigit(n) << endl;
    system("pause");
    return 0;
}