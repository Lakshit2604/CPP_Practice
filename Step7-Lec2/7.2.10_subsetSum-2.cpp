# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    void helper(int i ,int n, vector<int> &nums, vector<int> &ds, vector <vector<int>> &ans){
        if ( i== n){
            ans.push_back(ds);
            return;
        }
        for( int j = i; j < n; j++){
            if ( j == i || nums[j] != nums[j-1]){
                ds.push_back(nums[j]);
                helper(j+1,n, nums, ds, ans);
                ds.pop_back();
            }
        }
        ans.push_back(ds);   // Or call helper(n, n, nums, ds, ans); - This adds the ds only but takes extra time and space of rec call.
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans = {};
        vector <int> ds = {};
        helper(0, nums.size(), nums, ds, ans);
        return ans;
    }
};