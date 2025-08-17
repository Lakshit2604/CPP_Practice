# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

// Brute : valid for unicode char too
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp; 
        for (char c : s){
            mpp[c] += 1;
        }
        for (char c : t){
            mpp[c] -= 1;
        }
        for (auto it : mpp){
            if (it.second != 0) return false;
        }
        return true;
    }
};

// Optimal 
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> hash(26,0); 
        int n = size(s);
        int m = size(t);
        for (int i = 0; i < n; i++){
            hash[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < m; i++){
            hash[t[i] - 'a'] -= 1; 
        }
        for (int i : hash ){
            if (i != 0) return false;
        }
        return true;
    }
};