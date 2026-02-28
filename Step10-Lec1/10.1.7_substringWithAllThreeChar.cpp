# include <iostream>
# include <vector>
# include <set>
using namespace std;

// Brute
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for ( int i = 0; i < n; i++){
            set<int> st;
            for (int j = i; j < n; j++){
                st.insert(s[j]);
                if (st.size() == 3) ans++;
            }
        }
        return ans;
    }
};

// Slightly Better 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            int cntA = 0, cntB = 0, cntC = 0;
            for (int j = i; j < n ; j++){
                if (s[j] == 'a') cntA++;
                if (s[j] == 'b') cntB++;
                if (s[j] == 'c') cntC++;
                if (cntA == 1 && cntB == 1 && cntC == 1) {
                    ans += (n-j);
                    break;
                }
            }
        }
        return ans;
    }
};

// Optimal
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int indA = -1, indB = -1, indC = -1;
        vector <int> hash(3,-1);
        for (int i = 0; i < n; i++){
            hash[s[i] - 'a'] = i;
            ans += (min(hash[0], min(hash[1], hash[2])) + 1);
        }
        return ans;
    }
};