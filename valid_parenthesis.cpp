// Given a string containing just the characters 
// '(', ')', '{', '}', '[' and ']', determine 
// if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> map = {{')', '('}, {']', '['}, {'}', '{'}};
    for (auto it = s.begin(); it != s.end(); it++) {
        if (st.empty() || map[*it] != st.top())
            st.push(*it);
        else
            st.pop();
    }
    return st.empty();
}

int main() {
    string s = "{[]}";
    cout << isValid(s) << endl;
    system("pause");
    return 0;
}

