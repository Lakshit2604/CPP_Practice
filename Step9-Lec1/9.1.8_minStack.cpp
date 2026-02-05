# include <stack>
using namespace std;

// Brute
class MinStack {
public:
    stack <pair <int,int>> st;
    MinStack() {

    }
    
    void push(int val) {
        if (st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // Optimal 
 class MinStack {
public:
    stack <long> st;
    long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) st.push(val), mini = val;
        else{
            if ( val < mini){
                st.push(val + (val - mini));
                mini = val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if ( st.top() < mini){
            mini = 2* mini - st.top();
        }
        st.pop();
        if (st.empty()) mini = INT_MAX;
    }
    
    int top() {
        if ( st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */