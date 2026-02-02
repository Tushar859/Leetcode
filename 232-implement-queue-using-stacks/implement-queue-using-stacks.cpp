class MyQueue {
public:
    stack<int> s;
    stack<int> p;

    MyQueue() {}

    void push(int x) {
        p.push(x);
    }

    int pop() {
        if (s.empty()) {
            while (!p.empty()) {
                s.push(p.top());
                p.pop();
            }
        }
        int result = s.top();
        s.pop();
        return result;
    }

    int peek() {
        if (s.empty()) {
            while (!p.empty()) {
                s.push(p.top());
                p.pop();
            }
        }
        return s.top();
    }

    bool empty() {
        return s.empty() && p.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */