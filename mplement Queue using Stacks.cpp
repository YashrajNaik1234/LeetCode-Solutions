class MyQueue {
    stack<int> x, y;

public:
    MyQueue() {}

    void push(int z) {
        while (!x.empty()) {
            y.push(x.top());
            x.pop();
        }

        y.push(z);

        while (!y.empty()) {
            x.push(y.top());
            y.pop();
        }
    }

    int pop() {
        int y = x.top();
        x.pop();
        return y;
    }

    int peek() { return x.top(); }

    bool empty() { return (x.size() == 0); }
};
