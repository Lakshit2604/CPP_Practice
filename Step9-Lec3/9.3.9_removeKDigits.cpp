# include <iostream>
# include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack <char> st;
        int n = num.size();
        if (n == k) return "0";
        for ( int i = 0; i < n; i++){
            while (!st.empty() && k != 0 && st.top() > num[i]){ 
                st.pop();
                k--;
            }
            if (st.empty() && num[i] == '0') continue;
            st.push(num[i]); 
        }
        while (!st.empty() && k--) st.pop();
        if (st.empty()) return "0";
        while( !st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};