# include <iostream>
# include <vector>
using namespace std;

// Without duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int mini = INT_MAX;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[low] <= nums[high]) return min(nums[low], mini);
            if (nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};

// With Duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0; 
        int high = n - 1;
        int mini = INT_MAX;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                mini = min(mini, nums[low]);
                high--;
                low++;
                continue;
            }
            if (nums[low] <= nums[high]) return min(nums[low], mini);
            if (nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};

int main(){
    Solution sol;
    vector <int> arr;
    int input;
    for (int i = 0;  i < 6 ; i++){
        cin >> input;
        arr.push_back(input);
    }
    cout << sol.findMin(arr);
}