# include <iostream>
# include <string>
# include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n = s.size();
        for ( int i =0; i < n; i++){
            if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if (st.empty()) return false; 
                if (s[i] == ')' && st.top() == '(') st.pop();
                else if (s[i] == '}' && st.top() == '{') st.pop();
                else if (s[i] == ']' && st.top() == '[') st.pop();
                else return false;
            }
            else st.push(s[i]);
        }   
        if (st.empty()) return true;
        return false;
    }
};