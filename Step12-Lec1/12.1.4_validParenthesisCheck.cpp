# include <iostream>
# include <string>
using namespace std;

// Brute
class Solution {
private:
    bool solve(string& s,int i, int cnt){
        if ( i == s.size()) return (cnt) ? false: true;
        if ( cnt < 0) return false;
        if (s[i] == '(') return solve(s,i+1,cnt+1);
        if(s[i] == ')') return solve(s,i+1,cnt-1);
        if (s[i] == '*') {
            return solve(s,i+1,cnt) || solve(s,i+1,cnt+1) || solve(s,i+1,cnt-1);
        }
        return false;
    }
public:
    bool checkValidString(string s) {
        return solve(s,0,0);
    }
};

// Optimal
class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        for (char i : s){
            if( i == '(') min++, max++;
            else if (i == ')'){
                if (min -1 >= 0) min--;
                max--;
            }
            else{
                if (min -1 >= 0) min--;
                max++;
            }
            cout << min << ' ' << max << '\n';
            if ( max < 0) return false;
            
        }
        if (min == 0 || max == 0) return true;
        return false;
    }
};