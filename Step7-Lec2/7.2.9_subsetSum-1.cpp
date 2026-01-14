# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    void helper(int i, vector<int> &arr, int sum, vector<int> &ans){
        if ( i == arr.size()){
            ans.push_back(sum);
            return ;
        }
        helper(i+1, arr, sum + arr[i], ans);
        helper(i+1, arr, sum, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        helper(0, arr, 0, ans);
        return ans;
    }
};