# include <iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++){
            int zeroes = 0;
            int len = 0;
            for (int j = i; j < n; j++){
                if (nums[j] == 0){
                    if ( zeroes >= k) {
                        maxLen = max(maxLen, len);
                        break;
                    }
                    else zeroes++;
                }
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

// Better 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0, r = 0;
        int zeroes = 0;
        while (r < n){
            if (nums[r] == 0){
                if ( zeroes >= k) {
                    maxLen = max(maxLen, r-l);
                    while (nums[l] != 0){
                        l++;
                    } 
                    zeroes--;
                    l++;
                    continue;
                }
                else zeroes++;
            }
            r++;
        }
        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};

// Optimal 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0, r = 0;
        int zeroes = 0;
        while (r < n){
            if (nums[r] == 0) zeroes++;
            if ( zeroes > k){
                if ( nums[l] == 0) zeroes--;
                l++;
            }
            else {
                maxLen = max(maxLen, r-l);
            }
            r++;
        }
        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};