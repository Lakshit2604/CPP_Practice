# include <iostream>
# include <string>
# include <stack>
using namespace std;

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack <string> st;
        int n = exp.size();
        for (int i = 0; i < n ; i++){
            char s = exp[i];
            if ( s >= 'A' && s <= 'Z' || s >= 'a' && s <= 'z'){
                st.push(string(1, s));
            }
            else {
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                st.push('(' + top2 + s + top1 + ')');
            }
        }
        return st.top();
    }
};