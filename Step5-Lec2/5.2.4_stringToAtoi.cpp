# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int cnt = 0;
        int sign = 1;
        long long ans = 0;
        for (int i = 0; i < n; i++){
            if (cnt == 0 && s[i] == ' ' ) continue;
            else if (cnt == 0 && s[i] == '+') cnt = 1;
            else if (cnt == 0 && s[i] == '-') cnt = 1, sign = -1;
            else if (!isdigit(s[i])) break ;
            else {
                ans = (ans * 10) + (s[i]-'0');
                cnt = 1;
                if (ans * sign > INT_MAX ) return INT_MAX;
                if (ans * sign < INT_MIN ) return INT_MIN;
            }
        }
        return ans * sign;
    }
};