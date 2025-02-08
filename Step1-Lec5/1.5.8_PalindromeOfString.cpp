#include <iostream>
# include <cctype>
# include <string>
using namespace std;

// High time complexicity
class Solution {
public:
    bool isPalindrome(string &s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isupper(s[i])) s[i]= tolower(s[i]);
            if(!isalnum(s[i])){
            s.erase(i,1);     
            i--;
            n--;
            }    
        }
        if(s=="") return true;
        return ispal(0,s);
    }

    bool ispal(int i, string &s){
        if(i > s.size()/2) return true;
        if(s[i] != s[s.size()-i-1]) return false;
        return ispal(i+1, s);
    }
};

// low time complexicity : very much optimised
class Solution {
public:
    bool isPalindrome(string &s) {
        int n = s.size();
        int l= 0;
        int r = n-1;
        while (l<r){
            if(!isalnum(s[l])) r++;
            else if(!isalnum(s[r])) l--;
            else if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }    
};
int main (){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s);
    return 0;
}
