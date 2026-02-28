# include <iostream>
# include <map>
# include <string>
using namespace std;

// Brute
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++){
            int len = 0;
            map <char, int> mpp;
            for (int j = i ; j < n; j++){
                if (mpp.find(s[j]) != mpp.end()){
                    maxLen = max(len, maxLen);
                    break;
                }
                else {
                    mpp[s[j]] = 1;
                    len++;
                }
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

// Optimal 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();
        int maxLen = 0;
        int l = 0, r = 0;
        map <char, int> mpp;
        while( r < n){
            if (mpp.find(s[r]) != mpp.end()){
                maxLen = max(maxLen,r-l);
                while ( l < mpp[s[r]]){
                    mpp.erase(s[l]);
                    l++;
                }
                mpp[s[l]] = r;
                l++;
            }
            else {
                mpp[s[r]] = r ;
            }
            r++;
        }
        maxLen = max(maxLen,r-l);
        return maxLen;
    }
};