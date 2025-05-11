# include <iostream>
using namespace std;

class Solution {
    public:
      // Please change the array in-place
      void insertionSort(vector<int>& arr) {
          // code here
          for (int i =1 ; i < arr.size(); i++){
              int j = i;
              while (j>0 && arr[j-1]>arr[j]){
                  int temp = arr[j];
                  arr[j] = arr[j-1];
                  arr[j-1]= temp;
                  j--;
              }
          }
      }
  };