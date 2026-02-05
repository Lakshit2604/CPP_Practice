# include <string>
# include <stack>
using namespace std;

class Solution {
  private:
    int priority(char c){
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }
    
  public:
    string infixToPostfix(string& s) {
        // code here
        int n = s.size();
        string ans;
        stack <char> st;
         for (int i = 0; i < n ; i++){
             if ((s[i] >= 'A' && s[i] <= 'Z') ||
             (s[i] >='a' && s[i] <= 'z') ||
             (s[i] >= '0' && s[i] <= '9')){
                 ans.push_back(s[i]);
             }
             else if (s[i] == '(') st.push(s[i]);
             else if (s[i] == ')'){
                 while(!st.empty() && st.top() != '('){
                     ans.push_back(st.top());
                     st.pop();
                 }
                 if (!st.empty()) st.pop();
             }
             else {
                if (!st.empty() && priority(st.top()) == 3 && priority(s[i]) == 3) st.push(s[i]);
                else {
                    while (!st.empty() && priority(st.top()) >= priority(s[i])){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
             }
         }
         while (!st.empty()){
             ans.push_back(st.top());
             st.pop();
         }
         return ans;
    }
};
