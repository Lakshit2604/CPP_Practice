# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = sumArr(nums);
        while (low <= high){
            int mid = low + (high - low)/2;
            if (subArr(nums, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    int sumArr(vector <int> nums){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int subArr(vector<int> nums, int mid){
        int sum = 0, sub = 1;
        for(int i = 0; i < nums.size(); i++){
            if (sum + nums[i] <= mid) sum += nums[i];
            else sum = nums[i], sub++; 
        }
        return sub;
    }
};