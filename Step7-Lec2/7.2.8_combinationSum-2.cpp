# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void helper(int i , int k, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
        if ( k == 0){
            ans.push_back(ds);
            return;
        }
        if ( k < 0 || i == nums.size() ) return;
        for (int j = i; j < nums.size(); j++){
            if ( j == i || nums[j] != nums[j-1]){
                ds.push_back(nums[j]);
                helper(j+1, k - nums[j], nums, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <vector <int>> ans;
        vector<int> ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};