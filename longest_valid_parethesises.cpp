/* 1. push index of '(' and ')' into stack, when matched pop out;
2. the stack will only contain index of not matching parenthesises;
3. the interval between adjacent index of stack will be valid parenthesis
4. find longest interval, donnot forget corner case of the first and last 
*/

int longestValidParentheses(string s) {
    int longest = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == '(') {
            st.push(i);
        }
        else {
            if (!st.empty() && s[st.top()] == '(') {
                st.pop();
            }
            else {
                st.push(i);
            }
        }
    }
    if (st.empty()) {
        longest = s.size();
    }
    int a = s.size(), b = 0;
    while(!st.empty()) {
        b = st.top();
        st.pop();
        longest = max(longest, a - b - 1);
        a = b;
    }
    longest = max(longest, a);
    return longest;
}