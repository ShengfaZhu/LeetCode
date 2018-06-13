#include <iostream>
#include <string>
#include <cassert>
#include <stack>
using namespace std;

int extract_num(string& s, int start, int *num) {
    *num = 0;
    while (start < s.size()) {
        if (s[start] == ' ') {
            start++;
            continue;
        }
        if (s[start] < '0' || s[start] > '9')
            break;
        *num = *num * 10 + s[start] - '0';
        start++;
    }
    return start;
}

int calculate(string s) {
    assert(s.empty() == false);
    stack<int> st;
    int curr_num, i = extract_num(s, 0, &curr_num), j = 0;
    st.push(curr_num);
    while (i < s.size()) {
        j = extract_num(s, i + 1, &curr_num); 
        if (s[i] == '+')
            st.push(curr_num);
        if (s[i] == '-')
            st.push(-1 * curr_num);
        if (s[i] == '*') {
            int tmp = st.top();
            st.pop();
            st.push(tmp * curr_num);
        }
        if (s[i] == '/') {
            int tmp = st.top();
            st.pop();
            st.push(tmp / curr_num);
        }
        i = j;
    }
    int ans = st.top();
    st.pop();
    while (!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string s = " 3+5 / 2 ";
    cout << calculate(s) << endl;
    system("pause");
    return 0;
}