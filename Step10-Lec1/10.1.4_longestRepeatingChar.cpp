# include <iostream>
# include <vector>
using namespace std;

// Brute
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n ; i++){
            vector<int> hash(26, 0);
            int replace = 0;
            int maxFreq = 0;
            for (int j = i; j < n; j++){
                hash[s[j] - 'A'] ++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);
                replace = (j - i + 1) - maxFreq;
                if ( replace <= k) maxLen = max(maxLen, (j- i+ 1));
                else break;
            }
        }
        return maxLen;
    }
};

// Better
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int l = 0,  r = 0;
        vector<int> hash(26, 0);
        int replace = 0;
        int maxFreq = 0;
        while(r < n){
            hash[s[r] - 'A'] ++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            replace = (r - l + 1) - maxFreq;
            while ( replace > k){
                hash[s[l] - 'A']--;
                maxFreq = 0;
                for (int i : hash) maxFreq = max(maxFreq, i);
                l++;
                replace = (r-l+1) - maxFreq;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

// Optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int l = 0,  r = 0;
        vector<int> hash(26, 0);
        int replace = 0;
        int maxFreq = 0;
        while(r < n){
            hash[s[r] - 'A'] ++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            replace = (r - l + 1) - maxFreq;
            if ( replace > k){
                hash[s[l] - 'A']--;
                maxFreq = 0;
                for (int i : hash) maxFreq = max(maxFreq, i);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};