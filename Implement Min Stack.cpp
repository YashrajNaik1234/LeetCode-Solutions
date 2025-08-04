class MinStack {
    stack<long long int> st;
    long long mini = INT_MAX;
public:
    MinStack() {
        mini = LONG_LONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()) st.push(val), mini = val;
        else{
            if(val > mini) st.push(val);
            else st.push(2ll * val - mini), mini = val;
        }
    }
    
    void pop() {
        long long y = st.top(); st.pop();
        if(y < mini) mini = 2ll * mini - y;
    }
    
    int top() {
        if(st.top() > mini) return (int)st.top();
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};
