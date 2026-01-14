# include <iostream>
# include <string>
using namespace std;

// Implementation way 1 : making s by checking if bit set or not
class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector <string> ans ;
        for (int i = 0; i < (1<<n); i++){          // for 2^n use (1<<n)
            string s = "";
            for ( int j = 0; j < n; j++){
                char c = i & (1 << j) ? '1' : '0';
                s.insert(0, 1, c);
            }
            ans.push_back(s);
        }
        return ans;
    }
};

// Implementation way 2 : by replacing 1 if bit set in s of n 0's
class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector <string> ans ;
        for (int i = 0; i < (1<<n); i++){
            string s (n,'0');
            for ( int j = 0; j < n; j++){
                if (i & (1<<j)) s[n-j-1] = '1';
            }
            ans.push_back(s);
        }
        return ans;
    }
};