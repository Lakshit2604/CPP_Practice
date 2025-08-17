# include <iostream>
# include <vector>
using namespace std;

// floor
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1, floor = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if (arr[mid] <= x) floor = mid, low = mid + 1;
            else high = mid - 1;
        }
        return floor;  // or return high;
    }
};

// ceil
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1, ceil = -1;
        while (low <= high){
            int mid = (low + high)/2;
            if (arr[mid] >= x) ceil = mid, high = mid-1;
            else low = mid + 1;
        }
        return ceil;  // or return low and if low == n return -1;
    }
};