// 231. Power of Two
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    while (n) {
        if (n & 1 == 1)
            break;
        n = n >> 1;
    }
    return n == 1;
}

int main() {
    int n = 5;
    cout << isPowerOfTwo(n) << endl;
    system("pause");
    return 0;
}