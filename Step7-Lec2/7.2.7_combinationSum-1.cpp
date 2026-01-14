# include <iostream>
# include <vector>
using namespace std;

// Approach 1 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector <int> ds ;
        helper(0, candidates , target, ans, ds);
        return ans;
    }

    void helper(int i, vector <int> &nums, int k ,vector<vector<int>> &ans, vector<int> &ds){
        if (i == nums.size()){
            if (k == 0) ans.push_back(ds);
            return;
        }
        if ( nums[i] <= k){
            ds.push_back(nums[i]);
            helper(i, nums, k - nums[i], ans, ds);
            ds.pop_back();
        }
        helper(i+1, nums, k, ans, ds);
    }
};

// Approach 2 - can add case if k < 0 then return, no need to add explicitly the skip condition.
/// It will handle it automatically.