# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = size(s);
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < n; i++){
            if(s[i] == '('){
                if (cnt != 0) ans += s[i];
                cnt++;
            } 
            else{
                if (cnt-1 != 0) ans += s[i];
                cnt--;
            }
        }
        return ans;
    }
};