# include <stack>
using namespace std;

// Brute
class MyQueue {
public:
    stack <int> s1, s2;
    int size;
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        if (s1.empty()) s1.push(x);
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        size++;
    }
    
    int pop() {
        int data = s1.top();
        s1.pop();
        size--;
        return data;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return !size;
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


// Optimised push operation
class MyQueue {
public:
    stack <int> s1, s2;
    int size;
    MyQueue() {
        size = 0;
    }
    
    void push(int x) {
        s1.push(x);
        size++;
    }
    
    int pop() {
        if (size == 0) return -1;
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int data = s2.top();
        s2.pop();
        size--;
        return data;
    }
    
    int peek() {
        if (size == 0) return -1;
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return !size;
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