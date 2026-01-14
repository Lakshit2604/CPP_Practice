# include <iostream>
# include <stack>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
        int num = st.top();
        st.pop();
        sortStack(st);
        insertNum(st, num);
    }
    void insertNum(stack<int> &st, int num){
        if (st.empty() || num >= st.top()) {
            st.push(num);
            return;
        }
        int temp = st.top();
        st.pop();
        insertNum(st, num);
        st.push(temp);
    }
};
