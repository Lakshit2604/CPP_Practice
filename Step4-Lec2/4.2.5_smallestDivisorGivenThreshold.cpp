# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high){
            int mid = low + (high - low)/2;
            if (findSum(nums, mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    int findSum(vector <int> nums, int mid){
        int sum  = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += (nums[i] + mid - 1)/ mid;
        }
        return sum;
    }
};