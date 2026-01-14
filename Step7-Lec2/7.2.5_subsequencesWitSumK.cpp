# include <iostream>
# include <vector>
using namespace std;

// Brute : TLE error for big n values
class Solution {
public:
    void helper(int i, int k, vector<int> &nums, vector<vector<int>> & ans, vector<int> &ds){
        if ( i == nums.size()){
            if ( !ds.empty() && ds[0] + ds[ds.size() - 1] <= k ){
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(nums[i]);
        helper(i+1, k, nums, ans, ds);
        ds.pop_back();
        helper(i+1, k, nums, ans, ds);
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans;
        vector <int> ds;
        helper(0, target, nums, ans, ds);
        return ans.size() % (1000000007); 
    }
};

// Optimal : Recursive
class Solution {
public:
    void helper(int l, int r, int k, vector<int> &nums, int &cnt ){
        if ( l > r ) return;
        if (nums[l] + nums[r] <= k){
            cnt = (cnt + exp(2,(r-l))) % 1000000007;
            helper(l+1, r, k, nums, cnt);
        }
        else helper(l, r-1, k, nums, cnt);
    }

    long long exp(long long b, int n){
        if ( n == 0) return 1;
        if ( n == 1 ) return b ;
        if (n % 2 == 0) return exp((b*b)% 1000000007, n/2);
        return (b * exp(b, n -1)) % 1000000007;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        helper(0, nums.size()-1, target, nums, cnt);
        return cnt; 
    }
};

// Optimal : Iterative
class Solution {
public:
    long long exp(long long b, int n){
        if ( n == 0) return 1;
        if ( n == 1 ) return b ;
        if (n % 2 == 0) return exp((b*b)% 1000000007, n/2);
        return (b * exp(b, n -1)) % 1000000007;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1000000007;
        int cnt = 0;
        int l = 0;
        int r = n -1;
        while( l <= r){
            if ( nums[l] + nums[r] <= target){
                cnt = (cnt + exp(2,r-l)) % mod;
                l++;
            }
            else r--;
        }
        return cnt; 
    }
};