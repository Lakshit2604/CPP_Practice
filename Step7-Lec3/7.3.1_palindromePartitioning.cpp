# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    bool checkPalindrome(int i, int j, string &s){
        while( i <= j ){
            if (s[i] == s[j]) i++, j--;
            else return false;
        }
        return true;
    }
    
    void helper(int i, string &s, vector<vector<string>> &ans, vector<string> &ds){
        if (i == s.size()){
            ans.push_back(ds);
            return;
        }
        for (int j = i; j < s.size(); j++){
            if (checkPalindrome(i,j,s)){
                ds.push_back(s.substr(i, (j - i + 1)));
                helper(j+1, s, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector <string> ds;
        vector <vector<string>> ans;
        helper(0,s, ans, ds);
        return ans;
    }
};

int main(){
    Solution s;
    s.partition("aab");
    return 0;
}