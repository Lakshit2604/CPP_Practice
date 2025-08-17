# include <iostream>
using namespace std;

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        if (n == 1) return m;
        int low = 1;
        int high = m;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (pow(mid,n) == m) return mid;
            else if (pow(mid,n) < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};