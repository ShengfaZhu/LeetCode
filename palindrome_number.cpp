// Determine whether an integer is a palindrome. 
// An integer is a palindrome when it reads the same backward as forward.

// Example 1:
// Input: 121
// Output: true

// Example 2:
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. 
// From right to left, it becomes 121-. Therefore it is not a palindrome.
// Coud you solve it without converting the integer to a string?

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    int y = x;
    int reverse = 0;
    while(y != 0) {
        reverse = reverse * 10 + (y % 10);
        y = y / 10;
    }
    return reverse == x;
}

int main() {
    int x = -121;
    cout << isPalindrome(x) << endl;
    system("pause");
    return 0;
}