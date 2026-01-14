# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans ;
        string s = "(";
        helper(n,1,0, s, ans);
        return ans;
    }
    void helper(int n , int nOpen, int nClose, string &s, vector <string> &ans){
        if ( nClose == n && nOpen == n){
            ans.push_back(s);
            return;
        }
        if ( nOpen < n){
            s.push_back('(');
            helper(n,nOpen + 1, nClose, s, ans);
            s.pop_back();
        }
        if ( nClose < nOpen){
            s.push_back(')');
            helper(n, nOpen, nClose + 1, s, ans);
            s.pop_back();
        }
        return;
    }
};