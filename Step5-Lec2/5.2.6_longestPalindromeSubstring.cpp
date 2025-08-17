# include <iostream>
# include <string>
using namespace std;

// Brute
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxStr = "";
        for (int i = 0 ; i < n ; i++){
            for (int j = i ; j < n ; j++){
                int left = i, right = j;
                while ((left <= right) && (s[left] == s[right])){
                    left++;
                    right--;
                }
                if (left > right){
                    if ((j - i + 1) > maxStr.size()) maxStr = s.substr(i, j-i+1);
                }
            }
        }
        return maxStr;
    }
};

// Optimal
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxStr = "";
        maxStr += s[0];
        for (int i = 1; i < n; i++){
            int left = i-1;
            int right = i;
            while ((left >= 0) && (right < n) &&(s[left] == s[right])){
                if ((right - left + 1) > maxStr.size()) {
                    maxStr = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }

            left = i-1;
            right = i+1;
            while((left >= 0) && (right < n) && (s[left] == s[right])){
                if ((right - left + 1) > maxStr.size()){
                    maxStr = s.substr(left, right - left + 1 );
                }
                left--;
                right++;
            }
        }
        return maxStr;
    }
};