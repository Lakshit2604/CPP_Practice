# include <iostream>
using namespace std;

class Solution {
    public:
      // Function returns the second
      // largest elements
      int getSecondLargest(vector<int> &arr) {
          // Code Here
          int arrlen = arr.size();
          int sLargest = -1;
          int largest = arr[0];
          for (int i =0; i < arrlen; i++){
              if(arr[i] > largest){
                  sLargest = largest;
                  largest= arr[i];
              }
              else if (arr[i] < largest && arr[i] > sLargest){
                  sLargest = arr[i];
              }
          }
          return sLargest;
      }
  };