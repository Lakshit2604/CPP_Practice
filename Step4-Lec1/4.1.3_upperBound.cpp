# include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1, ans = n;
        while (low <= high){
            int mid = (low + high)/2;
            if (arr[mid] > target) ans = mid, high = mid-1;
            else low = mid+1;
        }
        return ans; // or return low;
    }
};