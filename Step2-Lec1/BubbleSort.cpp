# include <iostream>
using namespace std;

class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bubbleSort(vector<int>& arr) {
          // Your code here
          int swap=0;
          for (int i = arr.size()-1; i>0; i--){
              for (int j =0; j < i; j++){
                  if (arr[j] > arr[j+1]){
                      int temp = arr[j];
                      arr[j] = arr[j+1];
                      arr[j+1 ] = temp;
                      swap+=1;
                  }
              }
              if(swap== 0) break;
          }
      }
  };
  