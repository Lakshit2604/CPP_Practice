# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bin(nums, 0, n-1, target);
    }
    int bin(vector <int> & nums,int low, int high, int target){
        if (low > high) return -1;
        int mid = ((long long)low + high)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return bin(nums, low, mid-1, target);
        else return bin(nums, mid+1, high, target);
    }
};