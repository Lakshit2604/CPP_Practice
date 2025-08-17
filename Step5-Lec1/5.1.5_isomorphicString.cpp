# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

// By two unordered maps (by key and by value)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = size(s);
        unordered_map <char, char> mpp1, mpp2; 
        for (int i = 0; i<n; i++){
            if (mpp1.find(s[i]) == mpp1.end() && mpp2.find(t[i]) == mpp2.end()){
                mpp1.insert({s[i],t[i]});
                mpp2.insert({t[i],s[i]});
                s[i] = t[i];
            }
            else {
                s[i] = mpp1[s[i]];
            }
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
