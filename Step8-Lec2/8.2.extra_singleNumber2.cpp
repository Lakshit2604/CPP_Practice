# include <iostream>
# include <vector>
# include <map>
using namespace std;

// Brute 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map <int, int> mpp;
        for (int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        for (auto i : mpp){
            if (i.second == 1) return i.first;
        }
        return 0;
    }
};

// Better
class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 32; i++){
            int cnt = 0;
            for (int j = 0; j < n ; j++){
                if ((nums[j] & (1<<i)) != 0) cnt++;
            }   
            if (cnt % 3 != 0){
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};

// Better 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ptr = 1;
        while ( ptr < n){
            int curr = nums[ptr];
            int left = nums[ptr-1];
            if(left == curr) ptr += 3;
            else return left;
        }
        return nums[n-1];
        return 0;
    }
};

// Optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, twos = 0;
        for (int i = 0; i < n; i++){
            ones = (nums[i] ^ ones) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};