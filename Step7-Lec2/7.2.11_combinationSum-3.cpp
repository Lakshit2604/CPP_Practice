# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void helper(int i ,int j, int k , int n, vector <vector<int>> &ans, vector <int> &ds){
        if ( j == k){
            if ( n == 0) ans.push_back(ds);
            return;
        }
        if ( i > 9 || i > n ) return;
        ds.push_back(i);
        helper(i+1, j+1, k, n - i, ans, ds);
        ds.pop_back();
        helper(i+1, j, k, n, ans, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector <int>> ans;
        vector<int> ds;
        helper(1,0, k, n, ans, ds);
        return ans;
    }
};