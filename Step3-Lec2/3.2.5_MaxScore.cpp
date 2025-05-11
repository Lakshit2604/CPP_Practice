# include <iostream>
using namespace std;
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int i = 0;
        int sum = 0, maxsum = 0;
        int n = arr.size();
        while (i < n-1){
            int j = i+1;
            sum = arr[i] + arr[j];
            maxsum = max(maxsum, sum);
            i++;
        }
        return maxsum;
    }
};