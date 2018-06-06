// 150. Evaluate Reverse Polish Notation
int string2int(string s) {
    if (s.empty()) return 0;
    int sign = 1, i = 0;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    int num = 0;
    while (i < s.size()) {
        num = num * 10 + s[i] - '0';
        i++;
    }
    return sign * num;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string s: tokens) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            if (s == "+") st.push(op2 + op1);
            else if (s == "-") st.push(op2 - op1);
            else if (s == "*") st.push(op2 * op1);
            else if (s == "/") st.push(op2 / op1);
        }
        else{
            st.push(string2int(s));
        }
    }
    return st.top();
}