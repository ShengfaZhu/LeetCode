#include <iostream>
#include <memory.h>
using namespace std; 

void set(char* M, int k) {
    M[k >> 3] |= 0x80 >> (k & 0x07);
}

bool detect(char* M, int k) {
    return M[k >> 3] & (0x80 >> (k & 0x07));
}

// Eratothenes筛法
int countPrimes(int n) {
    int N = (n + 7) / 8;
    char* M = new char[N];// bitmap
    memset(M, 0, N);// initialization
    set(M, 0);// 0 isnot prime
    set(M, 1);// 1 isnot prime
    for (int i = 2; i < n; i++) {
        if (detect(M, i) == false) {
            int j = 2;
            while (j * i < n) {
                set(M, j * i);
                j++;
            }
        }
    }
    // counting numbers of primes;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (detect(M, i) == false) {
            cout << i << "\t";
            count++;
        }

    }
    return count;
}

int main() {
    int n = 20;
    cout << countPrimes(n) << endl;
    system("pause");
    return 0;
}