# include <queue>
using namespace std;

// 2 queue
class MyStack {
public:
    queue <int> q1,q2;
    int size;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push(x); 
        } 
        else {
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        size++;
    }
    
    int pop() {
        if (q1.empty()) return -1;
        int data = q1.front();
        q1.pop();
        size--;
        return data;
    }
    
    int top() {
        if (!q1.empty()) return q1.front();
        return -1;
    }
    
    bool empty() {
        return !size;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 // 1 queue
 class MyStack {
public:
    queue <int> q;
    int size;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q.push(x); 
        if (size != 0) {
            for (int i = 0; i < size; i++){
                q.push(q.front());
                q.pop();
            }
        }
        size++;
    }
    
    int pop() {
        if (q.empty()) return -1;
        int data = q.front();
        q.pop();
        size--;
        return data;
    }
    
    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }
    
    bool empty() {
        return !size;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */