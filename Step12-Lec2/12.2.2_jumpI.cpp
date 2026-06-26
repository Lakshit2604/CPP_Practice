# include <iostream>
using namespace std;

// Brute
class Solution {
private:
    bool solve(vector<int>&nums, int i){
        if ( i == nums.size()-1) return true;
        for (int j=1; j <= nums[i]; j++){
            if (solve(nums, i+j)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};

// Optimal
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for (int i = 0; i< n; i++){
            if (i > maxInd) return false;
            maxInd = max(maxInd, nums[i] + i);
        }
        return true;
    }
};