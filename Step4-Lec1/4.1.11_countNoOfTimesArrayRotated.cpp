# include <iostream>
# include <vector>
using namespace std;

// Without duplicates
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int mini = INT_MAX;
        int index = 0;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[low] <= nums[high]){
                if (nums[low] < mini){
                    mini = nums[low];
                    index = low;
                }
                return index;
            }
            if (nums[low] <= nums[mid]){
                if (nums[low] < mini){
                    mini = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else {
                if (nums[mid] < mini){
                    mini = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};

// With Duplicates
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int mini = INT_MAX;
        int index = 0;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                if (nums[low] < mini){
                    mini = nums[low];
                    index = low;
                }
                high--;
                low++;
                continue;
            }
            if (nums[low] <= nums[high]){
                if (nums[low] < mini){
                    mini = nums[low];
                    index = low;
                }
                return index;
            }
            if (nums[low] <= nums[mid]){
                if (nums[low] < mini){
                    mini = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else {
                if (nums[mid] < mini){
                    mini = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};