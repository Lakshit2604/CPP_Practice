# include <iostream>
# include <map>
using namespace std;

// Brute
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int ans = -1;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            map <char, int> mpp;
            for (int j = i; j < n; j++){
                if ((mpp.find(s[j]) == mpp.end()) && (mpp.size() == k)){
                    ans = max(ans, cnt);
                    break;
                }
                cnt++;
                mpp[s[j]] = 1;
            }
            if (mpp.size() == k) ans = max(ans, cnt);
        }
        return ans;
    }
};

// Better 
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int ans = -1;
        int l = 0, r = 0;
        map <char, int> mpp;
        while ( r < n){
            if ((mpp.find(s[r]) == mpp.end()) && (mpp.size() == k)){
                ans = max(ans, r-l);
                while (mpp.size() == k){
                    mpp[s[l]]--;
                    if (mpp[s[l]] == 0) {
                        mpp.erase(s[l]);
                    }   
                    l++;
                }
            }
            mpp[s[r]] += 1;
            r++;
        }
        if (mpp.size() == k) ans = max(ans, r-l);
        return ans;
    }
};

// Optimal 
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int ans = -1;
        int l = 0, r = 0;
        map <char, int> mpp;
        while ( r < n){
            mpp[s[r]] += 1;
            if (mpp.size() > k){
                    mpp[s[l]]--;
                    if (mpp[s[l]] == 0) {
                        mpp.erase(s[l]);
                    }   
                    l++;
                }
            if (mpp.size() == k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};