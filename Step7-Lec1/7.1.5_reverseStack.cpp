# include <iostream>
# include <stack>
using namespace std;

// By using another stack
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        stack<int> st1;
        while (!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        st = st1;
    }
};

// Reversing same stack
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        int num = st.top();
        st.pop();
        reverseStack(st);
        insertNum(st, num);
    }
    
    void insertNum(stack <int> &st, int num){
        if (st.empty()){
            st.push(num);
            return;
        }
        int temp = st.top();
        st.pop();
        insertNum(st,num);
        st.push(temp);
    }
};