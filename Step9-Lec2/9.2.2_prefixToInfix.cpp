# include <iostream>
# include <string>
# include <stack>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.size();
        stack<string> st;
        for (int i = n-1; i >= 0; i--){
            char s = pre_exp[i];
            if (s >= 'A' && s <= 'Z' || s >= 'a' && s <= 'z'){
                st.push(string(1,s));
            }
            else{
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                st.push('(' + top1 + s + top2 + ')');
            }
        }
        return st.top();
    }
};