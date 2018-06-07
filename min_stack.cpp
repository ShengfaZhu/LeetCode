// min stack using STACK(STL)
class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> st;
    long long min;
    MinStack() {
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(0);
            min = x;
        }
        else{
            st.push(x - min);
            if (x < min) min = x;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long top_value = st.top();
        if (top_value < 0) 
            min = min - top_value;
        st.pop();
    }
    
    int top() {
        long long top_value = st.top();
        if (top_value < 0)
            return min;
        return min + top_value;
    }
    
    int getMin() {
        return min;
    }
};