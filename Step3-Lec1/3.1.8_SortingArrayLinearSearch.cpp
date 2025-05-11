# include <iostream>
using namespace std;

class Solution {
    public:
      // Function to find element in sorted array
      // arr: input array
      // k: element to be searched
      bool searchInSorted(vector<int>& arr, int k) {
          // Your code here
          for (int i : arr){
              if(i == k ){
                  return true;
              }
          }
          return false;
      }
  };
  