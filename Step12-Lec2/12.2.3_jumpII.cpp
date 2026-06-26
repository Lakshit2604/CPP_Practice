# include <iostream>
using namespace std;

// Brute
class Solution {
private:
    int solve(vector<int>&nums, int i, int cnt){
        if ( i == nums.size()-1) return cnt;
        int mini = nums.size();
        for (int j = 1; j <= nums[i]; j++){
            if (i+j >= nums.size()) break;
            mini = min(mini, solve(nums,i+j,cnt+1));
        }
        return mini;
    }
public:
    int jump(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};

// Optimal
class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        int l= 0, r = 0;
        int cnt = 0;
        while( r < n){
            if ( r == n-1) return cnt;
            int maxInd = 0;
            while (l <= r){
                maxInd = max(maxInd, l+nums[l]);
                l++;
            }
            cnt++;
            l=r+1;
            r=maxInd;
        }
        return cnt;
    }
};