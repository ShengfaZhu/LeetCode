#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printProb(int n) {
    if (n <= 0) return;
    vector<vector<int> > num_freq(2, vector<int>(6 * n + 1, 0));
    int flag = 0;
    const int max_value = 6;
    double total = pow(double(max_value), n);
    // initialization
    for (int i = 1; i <= max_value; ++i) {
        num_freq[flag][i] = 1;
    }
    // iterative to calculate frequence
    while (--n) {
        flag = 1 - flag;
        for (int i = 1; i < num_freq[flag].size(); ++i) {
            num_freq[flag][i] = 0;
            for (int k = 1; k <= max_value; ++k) {
                if ((i - k) > 0) {
                    num_freq[flag][i] += num_freq[1 - flag][i - k];
                }
            }
        }
    }
    // calculate prob
    for (int i = 1; i < num_freq[flag].size(); ++i) {
        double prob = double(num_freq[flag][i]) / total;
        cout << i << ": " << prob << endl;
    }
}

int main()
{
    int n = 2;
    printProb(n);
    system("pause");
    return 0;
}