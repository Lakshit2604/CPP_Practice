# include <iostream>
using namespace std;
class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        if (n < 1) return 0;
        return pow(n,3) + sumOfSeries(n-1);
    }
};