// Given a non-empty array of digits representing a 
// non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit 
// is at the head of the list, and each element in the array 
// contain a single digit.
// You may assume the integer does not contain any leading zero, 
// except the number 0 itself.
// Example 1:
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> res(digits);
    int step = 0;
    for (int i = res.size() - 1; i >= 0; i--) {
        int tmp = 0;
        if (i == res.size() - 1) {
            tmp = res[i] + 1;
        }
        else {
            tmp = res[i] + step;
        }
        if (tmp >= 10) {
            step = 1;
            tmp = tmp - 10;
            res[i] = tmp;
        }
        else {
            res[i] = tmp;
            step = 0;
            break;
        }
    }
    if (step == 1) {
        res.insert(res.begin(), 1);
    }
    return res;
}

int main() {
    vector<int> digits = {0};
    vector<int> res = plusOne(digits);
    for (int& i : res) {
        cout << i;
    }
    system("pause");
    return 0;
}