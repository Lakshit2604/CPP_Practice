# include <iostream>
using namespace std;

class Solution {
    public:
      int largest(vector<int> &arr) {
          // code here
          int max = arr[0];
          for (int i : arr){
              if (i > max) max = i;
          }
          return max;
      }
  };