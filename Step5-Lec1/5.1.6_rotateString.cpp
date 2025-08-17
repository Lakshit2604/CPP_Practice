# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

// 1.
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = size(s);
        int m = size(goal);
        if (n != m) return false;
        for (int i = 0; i <= n; i++){
            if (s == goal) return true;
            char temp = s[0];
            for (int j = 0; j < n-1 ; j++){
                s[j] = s[j+1];
            }
            s[n-1] = temp;
        }
    return false;
    }
};

// 2.
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = size(s);
        int m = size(goal);
        if (n != m) return false;
        s += s;
        if (s.find(goal) != string::npos) return true;
    //  if (s.find(goal) < 2*n) return true;  (Another logic)
    return false;
    }
};