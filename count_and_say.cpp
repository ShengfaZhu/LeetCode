// The count-and-say sequence is the sequence of 
// integers with the first five terms as following:
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of 
// the count-and-say sequence.
// Note: Each term of the sequence of integers will 
// be represented as a string.

#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    if (n == 1)
        return "1";
    string str = countAndSay(n - 1), res = "";
    int i = 0;
    while(i < str.size()) {
        int count = 1;
        int j = i + 1;
        while(j < str.size() && str[j] == str[i]) {
            j++;
            count++;
        }
        res = res + to_string(count);
        res = res + str[i];
        i = j;
    }
    return res;
}

int main() {
    int i = 5;
    cout << countAndSay(i) << endl;
    system("pause");
    return 0;
}