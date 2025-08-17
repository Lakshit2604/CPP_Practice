# include <iostream>
# include <string>
# include <vector>
using namespace std;

// My approach : Brute
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        string check = s[0];
        for (string i : s){
            check = min(check,i);
        }

        for (int i = 0; i < size(check); i++){
            for (int j = 0; j< s.size(); j++){
                if (check[i] != s[j][i]) return ans;
            }
            ans += check[i];
        }
        return ans;
    }
};

// Dictionary (YT) : Optimal
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int maxind = -1;
        for (int i = 0; i < size(s[0]); i++){
            if (s[0][i] == s[n-1][i]) maxind = i;
            else break;
        }
        return s[0].substr(0, maxind+1);
    }
};