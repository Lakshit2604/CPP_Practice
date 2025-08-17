# include <iostream>
# include <vector>
using namespace std;

// lower bound and upper bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (lowerBd(nums, target) == n || nums[lowerBd(nums,target)] != target) return {-1,-1};
        return {lowerBd(nums,target), upperBd(nums,target)-1};
    }
    int lowerBd (vector <int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + (high - low)/2) ;
            if (nums[mid] >= target) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
    int upperBd (vector <int> &nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + (high - low)/2) ;
            if (nums[mid] > target) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};

// Normal Binary Search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        if (first == -1) return {-1,-1};
        int second = secondOcc(nums, target);
        return {first, second};
    }
    int firstOcc(vector <int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n -1 ;
        int first = -1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target) first = mid, high = mid -1 ;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return first;
    }
    int secondOcc(vector <int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1 ;
        int second = -1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target) second = mid, low = mid + 1 ;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return second;
    }
};