# include <iostream>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort (bt.begin(), bt.end());
        int n = bt.size();
        long sum = 0, presum = 0;
        for ( int i = 1; i < n; i++){
            presum += bt[i-1];
            sum += presum;
        }
        return (sum / n);
    }
};