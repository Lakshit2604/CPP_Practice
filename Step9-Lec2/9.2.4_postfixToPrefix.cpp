# include <iostream>
# include <string>
# include <stack>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack <string> st;
        int n = post_exp.size();
        for ( int i = 0; i < n; i++){
            char s = post_exp[i];
            if ( s >= 'A' && s <= 'Z' || s >= 'a' && s <= 'z'){
                st.push(string(1,s));
            }
            else{
                string top1 = st.top();
                st.pop();
                string top2 = st.top();
                st.pop();
                st.push(s + top2 + top1);
            }
        }
        return st.top();
    }
};