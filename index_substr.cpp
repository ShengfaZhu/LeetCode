// Return the index of the first occurrence of needle 
// in haystack, or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int ind = -1, sz = needle.size();
    if (haystack.size() < sz)
        return ind;
    for (int i = 0; i < haystack.size() - sz + 1; i++) {
        if (haystack.substr(i, sz) == needle) {
            ind = i;
            break;
        }
    }
    return ind;
}

int main(){
    string hay = "aaaaa", needle = "";
    int ind = strStr(hay, needle);
    cout << ind << endl;
    system("pause");
    return 0;
}
