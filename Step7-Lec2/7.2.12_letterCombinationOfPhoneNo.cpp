# include <iostream>
# include <vector>
# include <string>
# include <map>
using namespace std;

class Solution {
public:
    void helper(int i , string digits, map<char, string> &mpp, vector <string> &ans, string &ds){
        if (i == digits.size()){
            if (!ds.empty()) ans.push_back(ds);
            return;
        }
        for ( int j = 0; j < mpp[digits[i]].size(); j++){
            ds.push_back(mpp[digits[i]][j]);
            helper(i+1, digits, mpp, ans, ds);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds;
        map <char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        helper(0, digits, mpp, ans, ds);
        return ans;
    }
};