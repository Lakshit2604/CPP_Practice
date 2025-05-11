# include <iostream>
using namespace std;

class Solution {
    public:
      // Please change the array in-place
      void insertionSort(vector<int>& arr) {
          // code here
          RecInsertion(arr, 1);
      }
      void RecInsertion(vector <int>&arr, int i){
          if(i == arr.size()) return;
          int j =i;
          while (j >0 && arr[j-1] > arr[j]){
              int temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
          }
          RecInsertion(arr, i+1);
      }
  };