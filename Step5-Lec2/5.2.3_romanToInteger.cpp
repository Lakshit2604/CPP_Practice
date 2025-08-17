# include <iostream>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map <char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5; 
        roman['X']= 10; 
        roman['L']= 50;
        roman['C'] = 100;
        roman['M'] = 1000; 
        roman['D'] = 500;
        int result = 0;
        for (int i = 0; i < n-1 ; i++){
            if (roman[s[i]] < roman[s[i+1]]) result -= roman[s[i]];
            else result += roman[s[i]];
        }
        return result + roman[s[n-1]];
    }
};