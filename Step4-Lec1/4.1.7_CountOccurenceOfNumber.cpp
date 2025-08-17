# include <iostream>
# include <vector>
using namespace std;

// finding occurence of target & target + 1 by only 1 fucntion.
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int first = bs(arr, target);
        if (first == -1 || first == n ) return 0;
        int last = bs(arr, target + 1) -1;
        return last - first + 1;
        
    }
    int bs (vector <int> &arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n -1 ;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
