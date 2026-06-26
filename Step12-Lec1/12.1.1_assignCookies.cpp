# include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        int n = s.size();
        int m = g.size();
        while ( l < m && r < n){
            if (s[r] >= g[l]) {
                l++;
                r++;
            }
            else r++;
        }
        return l;
    }
};