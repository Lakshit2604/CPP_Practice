# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
// Brute
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            unordered_map <int, int> mpp;
            for (int j = i ; j < n; j++){
                mpp[nums[j]] = 1;
                if (mpp.size() == k){
                    ans++;
                }
                if (mpp.size() > k) break;
            }
        }
        return ans;
    }
};

// Opitmal
class Solution {
private:
    int NumSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int ans = 0;
        unordered_map <int, int> mpp;
        int l = 0, r = 0;
        while (r < n){
            mpp[nums[r]]++;
            while ( mpp.size() > k){
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return NumSubarray(nums, k) - NumSubarray(nums, k-1);
    }
};