# include <iostream>
# include <stack>
using namespace std;

// Mehtod - 1 : Stack
class Solution {
public:
    int maxDepth(string s) {
        int n = size(s);
        int ans = 0;
        stack <char> st;
        for (int i = 0 ; i< n; i++){
            if (s[i] == '('){
                st.push(s[i]);
            }
            else if (s[i] == ')'){
                ans = max(ans, (int)size(st));
                st.pop();
            }
        }
        return ans;
    }
};

// Method - 2 : Simple loop
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0, cnt = 0;
        for (int i = 0 ; i< n; i++){
            if (s[i] == '('){
                cnt++;
            }
            else if (s[i] == ')'){
                ans = max(ans, cnt);
                cnt--;
            }
        }
        return ans;
    }
};