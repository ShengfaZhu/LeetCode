#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
f(n, m) = 0, n = 1;
f(n, m) = [f(n-1, m) + m] % n, n > 1
*/
int lastNumberInCircle(int n, int m) {
    if (n < 1  || m < 1) {
        return -1;// invalid input
    }
    int last = 0;
    for (int i = 2; i <= n; ++i) {
        last = (last + m) % i;
    }
    return last;

}

int main()
{
    int n = 5, m = 3;
    cout << lastNumberInCircle(n, m) << endl;
    system("pause");
    return 0;
}