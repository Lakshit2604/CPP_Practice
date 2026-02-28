# include <iostream>
# include <vector>
# include <string>
using namespace std;

// Brute
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if ( m < n) return "";
        int minLen = INT_MAX;
        int stInd = 0;
        vector <int> hash(123,0);
        for (char i : t){
            hash[i]++;
        }
        for (int i = 0; i < m; i++){
            vector <int> arr = hash;
            int cnt = 0;
            for (int j = i ; j < m; j++){
                if (arr[s[j]] > 0){
                    cnt++;
                }
                arr[s[j]]--;
                if (cnt == n){
                    if ( j - i + 1 < minLen){
                        minLen = j-i+1;
                        stInd = i;
                    }
                    break;
                }
            }
        }
        return (minLen != INT_MAX) ? s.substr(stInd, minLen) : "";
    }
};

// Optimal
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if ( m < n) return "";
        int minLen = INT_MAX;
        int stInd = 0;
        int l = 0, r = 0;
        vector <int> hash(123,0);
        for (char i : t){
            hash[i]++;
        }
        int cnt = 0;
        while ( r < m){
            if (hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == n){
                if ( r - l + 1 < minLen){
                    minLen = r-l+1;
                    stInd = l;
                }
                hash[s[l]]++;
                if ( hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        cout << minLen;
        cout << stInd;
        return (minLen != INT_MAX) ? s.substr(stInd, minLen) : "";
    }
};