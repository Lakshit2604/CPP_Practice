# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = size(s);
        string ans = "";
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++){
            string word = "";
            if (s[i] == ' ') continue;
            while (i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            ans += ' ' + word;
        }
        return ans.substr(1);
   }
};