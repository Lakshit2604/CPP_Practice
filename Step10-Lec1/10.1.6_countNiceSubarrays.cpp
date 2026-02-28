# include <iostream>
using namespace std;

// Brute
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = i ; j < n; j++){
                if (nums[j] & 1 == 1){
                    if (cnt < k) cnt++;
                    else break;
                }
                if ( cnt == k) ans++;
            }
            // if ( cnt == k) ans++;
        }
        return ans;
    }
};

// Better
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        unordered_map<int, int> mpp = {{0,1}};
        for (int i = 0; i < n; i++){
            if (nums[i] & 1 == 1) cnt++;
            int rem = cnt - k;
            ans += mpp[rem];
            mpp[cnt]++;
        }
        return ans;
    }
};

// Optimal
class Solution {
private:
    int cntSubarray(vector<int> & nums, int k){
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        int l = 0, r = 0;
        while (r < n){
            if ((nums[r] & 1) == 1) cnt++;
            while ( cnt > k) {
                if ((nums[l] & 1) == 1) cnt--;
                l++; 
            }
            r++;
            ans += (r -l);
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntSubarray(nums, k) - cntSubarray(nums, k-1);
    }
};