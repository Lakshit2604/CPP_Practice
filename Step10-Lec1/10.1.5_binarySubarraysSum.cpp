# include <iostream>
using namespace std;

// Brute
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i ; j < n; j++){
                if (nums[j] == 1){
                    if (sum < goal) sum++;
                    else break;
                }
                if ( sum == goal) ans++;
            }
            // if ( cnt == k) ans++;
        }
        return ans;
    }
};

// Better
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int n = nums.size();
        int ans = 0;
        int cnt = 0;
        unordered_map<int, int> mpp = {{0,1}};
        for (int i = 0; i < n; i++){
            if (nums[i] & 1 == 1) cnt++;
            int rem = cnt - goal;
            ans += mpp[rem];
            mpp[cnt]++;
        }
        return ans;
    }
};

// Optimal
class Solution {
private:
    int cntSubarray(vector<int> &nums, int goal){
        if( goal < 0) return 0;
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        int l = 0, r = 0;
        while( r < n){
            if (nums[r] == 1) cnt++;
            while(cnt > goal){
                if (nums[l] == 1) cnt--;
                l++;
            }
            r++;
            ans += (r -l);
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {  
        return cntSubarray(nums, goal) - cntSubarray(nums, goal - 1);
    }
};